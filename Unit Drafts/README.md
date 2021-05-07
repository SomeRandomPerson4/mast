# Unit Drafts

These are units that either do not have enough problems or are missing some theory. If you want to contribute to either, please submit a pull request when you are done. No commits are too small, so please don't sit on them.

## Environments

There are a number of environments present in dennis.sty. Please use them instead of manually writing things such as
	
	\textbf{Walkthrough:}
	\begin{enumerate}
	\item Step 1
	\end{enumerate}

The list of all available environments follows:

	theo
	pro
	fact
	claim
	corollary
	lemma
	defi
	exam
	exer
	sol
	remark
	walk
	prob

If there are any environments you find yourself needing, submit an issue (here or on geometryexplorer) or a pull request on my personal website's repository.

## Problems and point values

Make sure you adhere to the 1,2,4,6,9,13 point value standard. To input a problem, just type

	\begin{prob}[source]{points}
	Problem statement
	\end{prob}
	
Make sure you have the most recent version of dennis.sty (as of 5/3/2021).

Source is an optional argument. Please do not put [] if there is no source.

## Diagrams

If you know asy/tikz, please include diagrams in those languages. If you don't, DO NOT half-ass any diagrams by screenshotting. Just leave a comment
	% DIAGRAM NEEDED
and raise an issue so we know to look at it.

## When to commit

Please run the unit idea by me first. Once you've gotten approval, you can commit whenever you're done with an editing session or whatever. (Just don't sit on commits for days because other people may want to edit stuff too.)
