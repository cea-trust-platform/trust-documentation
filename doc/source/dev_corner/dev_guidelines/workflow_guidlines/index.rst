Workflow guidlines
==================

Git
---

TRUST uses Git for versioning. Here are some good practices regarding Git when you are a TRUST developer:

When you start a new development, create a branch that starts with your initials, then a slash then the name of your development.
Commit messages on your branch should follow this pattern:

.. code-block:: bash

     [Name_of_your_dev] A brief message that highlights the modifications you want to commit

     If needed, a longer message that gives more details regarding your development.

Squash your work commits so that the branch history remains clean and each commit compiles separately.
Do not use ``git merge``; for TRUST, we use ``git rebase``.
Try to rebase regularly onto the origin/next branch; it will save you quite some time before integration.
When writing your pull request, ensure that you are extensive in the description of what you have done, it will make the life of the reviewer easier.

Verification and Validation
---------------------------

Check that your developments do not break anything that already exists by running: 

.. code-block:: bash

	cd $TRUST_ROOT
	make ctest_optim && make ctest_debug

Each new development must come with a validation form or a test case before requesting a pull request
You can also use unit tests for testing parts of your code, see ``$TRUST_ROOT/tests/UnitTests`` for examples

 
