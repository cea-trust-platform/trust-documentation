""" This script :
- scans all the MD files found in 
  srcs/
- replace all the tags of the form
  :code:`class_name::method_name`
  by a proper HTML link to the Doxygen part of the documentation
- results are output in 
  .srcs_processed/  
(which is ignored in git)

"""

from pathlib import Path
import glob
import os

rst_content = {}

def clean_create_dirs():
    import shutil
    root = Path(__file__).parents[0]
    src_dir = root / "srcs"
    if not src_dir.exists():
        raise Exception(f"Directory {str(src_dir)} does not exist!")
    out_dir = root / ".srcs_processed"
    #if out_dir.exists():
    #    print(f"Cleaning previous processed directory: {str(out_dir)}")
    #    shutil.rmtree(out_dir)
    #out_dir.mkdir()
    return src_dir, out_dir  

def html_cls_file(cls_nam):
    ret = []
    for c in cls_nam:
        ret.append(c)
        if c == "_" : ret.append(c)
    return "class" + ''.join(ret) + ".html"
        
def build_ref_map(src_dir):
    """ Scan all RST files, and replace ':code:`class::func`' tags
    """
    global rst_content
    
    import re
    pattern = os.path.join(str(src_dir), "**", "*.rst")
    g = glob.glob(pattern, recursive=True)
    # First, build map
    rg = re.compile(r":code:`([a-zA-Z0-9_]+)(::([a-zA-Z0-9_]+)(\(\))?)?`")
    cod_map = {}  # Key is a pair of (class, function) e.g. ('Champ_front_base', 'associer_fr_dis_base')
                  # Value is a HTML link, e.g. 'doxy/classBoundary__field__inward.html#a62c2232002d9fb3bd0c5362867279082'
    for f_nam in g:
        with open(f_nam, "r") as f:
            ls = f.readlines()
            for lin_num, l in enumerate(ls):
                if m:=rg.search(l.strip()):
                    cls, func = m.group(1), ""
                    if m.group(3):
                        func = m.group(3)
                    cod_map[(cls, func)] = f_nam
                    s, e = m.span()
                    l2 = l.replace(l[s:e], f":code:`{cls}::{func}`")  # Standardize tag for later replacement
                    rst_content.setdefault(f_nam, []).append(l2)
                elif ":code:" in l:
                    raise Exception(f"File {f_nam}, misformatted 'code' tag at line #{lin_num+1}")
                else:
                    rst_content.setdefault(f_nam, []).append(l)
    # Now look for proper HTML reference
    # TODO could be more efficient - scan each HTML only once.
    for cls, func in cod_map:
        k = (cls,func)  # Key 
        html_nam = html_cls_file(cls)
        tag = ""
        # Check HTML file for the class and potentially find proper function reference inside it:
        html_pth = src_dir / ".." / ".." / "build" / "html" / "doxy" / html_nam
        rst_nam = cod_map[k]
        cod_map[k] = None
        if not html_pth.exists():
            raise Exception(f"Class '{cls}' not found in Doxygen doc! (reference used in RST file '{rst_nam}')") 
        if func != "":
            rg = re.compile(r"<a class=\"[^\"]+\" href=\"([^\"]+)\">" + func + "</a>")
            with open(html_pth) as f:
                for l in f.readlines():
                    if m := rg.search(l.strip()):
                        cod_map[k] = m.group(1)
                        break
            if cod_map[k] is None:
                raise Exception(f"Function '{func}' not found in Doxygen generated file for class '{cls}' - reference was declared in RST file {rst_nam}")
        else:
            cod_map[k] = html_nam
            
    return cod_map    

def format_link(url, cls, func, level):
    url = "../" * level + f"doxy/{url}"
    if func == "":
        nam = cls
    else:
        nam = f"{cls}::{func}()"
    link = f"`{nam} <{url}>`__"
    return link

def rewrite_rst(src_dir, out_dir, cod_map):
    """ Rewrite all rst files with the reference map
    """
    global rst_content

    for f_nam, content in rst_content.items():
        fn_out = Path(f_nam.replace(str(src_dir), str(out_dir)))
        end = f_nam.replace(str(src_dir), "")
        level = end.count("/")
        fn_out.parents[0].mkdir(parents=True, exist_ok=True)
        for k,v in cod_map.items():
            cls, func = k[0], k[1]
            orig = f":code:`{k[0]}::{k[1]}`"  # rebuild standard key
            link = format_link(v, cls, func, level)
            for i, c in enumerate(content):
                content[i] = c.replace(orig, link)
        with open(fn_out, "w") as f_out:
            f_out.write(''.join(content))
            
def do_the_job():
    src_dir, out_dir = clean_create_dirs()
    cod_map = build_ref_map(src_dir)
    rewrite_rst(src_dir, out_dir, cod_map)

if __name__ == "__main__":
    do_the_job()

