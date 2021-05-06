# For people less experienced with git/latex

If you do not have tex locally installed on your computer, please submit an ISSUE and describe what change you want made.

If it is a code change, label it as "edits." Use other labels as appropriate.

# For people more experienced with git/latex

**Get a copy of dennis.sty, fonts.tex, mathOperators.tex, and tikzMacros.tex from** https://github.com/chennisden/geometryexplorer/tree/gh-pages/texmf/tex/latex. It is also highly recommended you get universal.tex.

You need a working knowledge of TeX Live and Git (as well as both of these installed) in order to do this. If you want help feel free to DM me (Dennis).

You should clone the repo to start, and pull before any "editing sessions."

For any "obvious errors" (say I forgot to add a parenthesis, added an extra, there's some TeX error, or I wrote $1+1=3$) you can just feel free to commit, I can see what happens because there's version control

Please send PRs (Pull requests) for any larger changes so staff can look at them.

TeX includes a bunch of junk whenever you compile so PLEASE make sure your gitignore is correct, it should absolutely not contain any latexmk files or whatever. It's also possible to avoid having these files pushed by not running `git add` on them.

# Quote suggestions

Even if you know how to PR, please submit all quote suggestions as issues. Something of the form

	CQV Perspectives "abcde"

will work. Please tag all such issues as quotes.

# Missing solutions or diagrams

You do not need to send an issue for every problem without a solution, but if you feel like it's a problem that particularly needs one, please submit an issue. Please tag as "No solution."

You are encouraged to write the solution if you can.

The same applies for diagrams.

## How to emphasize answers

Do not use `\boxed`. Use `\ansbold{answer}`.
