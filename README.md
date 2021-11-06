# MAST Materials

## Introduction

"Woah, this repository is public? Does that mean I can access the materials without being part of the program?"

Yes and no, respectively. The repository is public because it has no reason to be private (you can't access sensitive materials or information from here unless you have access). Here are some benefits as to it being public:
- I can put contribution instructions in the public README.
- Because [mast-web](https://github.com/mathadvance/mast-web) is going to work with the **precise** structure of this repository, open-sourcing it will make the mast-web technology more clear to outsiders.

## Submodules

How materials work is they are placed in git submodules. The structure of each submodule is quite simple: a `.tex` file and the corresponding `.pdf` file. Each material must be compiled with [lucky.cls](https://github.com/chennisden/chennistex). 

A couple of submodules will be made public (CQV-Perspectives is the first I plan to make public). This is just so the submodule structure & expectations can be made even more clear.

**ALL** submodules must belong to `mathadvance` -- that way, we (mathadvance) actually have control over our own content.

## Contributor Guidelines

Please read the following if you are interested in contributing material to the MAST program.

Disclaimer: If you contribute material to MAST and we accept it, **it becomes ours**. This is just so we don't face the small risk that someone decides to take their repository down from under our noses.

Typically, I am very liberal with what contributors can do with their material (and MAST material in general). This is only possible because there's a large degree of trust involved. **If you don't trust us to do right by your material, don't contribute it.**

To contribute material and get it approved, here is what you should do:

1. Create a git repository with a `.tex` and `.pdf` file of your material (compiled in `lucky.cls`) and push it to your personal GitHub account. (Make sure your `.gitignore` ignores any compiled files. A sample can be found in this repository's `.gitignore`.)

2. Share your GitHub repository with me (my username is `chennisden`). Please give me permission to add other people as I see fit, because I may have other MAST staff look over it as well.

3. Contact me (Dennis Chen) in some way to let me know your repository exists. One option is emailing me at [dchen@mathadvance.org](mailto:dchen@mathadvance.org).

4. Only once your material is approved, transfer ownership of the repository to the mathadvance GitHub organization. (If you are a first-time contributor, you will need to be added to mathadvance.)

5. Create a pull request in this directory that adds your repository as a git submodule in the appropriate directory.

If you don't know how to do any of these steps, that's OK. Contact me and I'll walk you through it (but do please try to use Google before you contact me, many of these steps are quite simple). If you really don't have time, I can just add your files to the right place myself.
