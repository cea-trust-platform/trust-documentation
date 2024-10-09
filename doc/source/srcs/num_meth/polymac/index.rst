PolyMAC discretisations
=======================

=================
Doc trust PolyMAC
=================

:Author: Guillaume Jomee

.. role:: raw-latex(raw)
   :format: latex
..

Introduction
============

In TRUST code (:raw-latex:`\cite{trustonline}`), different numerical
schemes are availabe to the user. A familly of discretisation, called
PolyMAC, has been developped since 2018. Three PolyMAC have been
constructed, using a Finite Volume (FV) framework on a staggered mesh so
as to extend the MAC scheme developped in
:raw-latex:`\cite{harlow1965numerical}` to complex grids:

-  PolyMAC : based on a Compact Discrete Operator (CDO) approach, such
   as the one presented in :raw-latex:`\cite{bonelle2014}`,
   :raw-latex:`\cite{milani2020}`

-  PolyMACP0 : based on MPFA approach, such as the one presented in
   :raw-latex:`\cite{aavatsmark2002introduction}`
   :raw-latex:`\cite{Lepot05}`, :raw-latex:`\cite{droniou2014finite}`

-  PolyMACP0P1NC : based on a Hybrid Finite Volmue (HFV) approach, such
   as the one presented in :raw-latex:`\cite{eymard2007}`,
   :raw-latex:`\cite{eymard2010discretization}`

In the following, a brief description of PolyMAC and PolyMAC_P0 will be
given. Main steps of the discretisation of incompressible Navier-Stokes
equations using this two approaches will also be introduced.

Notations
=========

.. math::

   \begin{aligned}
   & \partial_{t} \left( u \right) + \nabla \cdot \left( u \otimes u \right) + \nabla p - \mu \nabla \wedge \omega = \mathcal{S} \ , \\
   & \nabla \cdot u = 0 \ ,\\
   & \omega - \nabla \wedge u = 0 \ .\end{aligned}

