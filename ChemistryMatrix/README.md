<h1>Chemistry Matrix Project</h1>

<p>The purpose of this project is to caclulate the pairwise stats of players to find strong pairs of players that do well together from a statistical standpoint at even strength.  The data used for this project is from the Westshore Wolves Junior B Club. </p>

<h2>Input</h2>

<p>To run this program the suggested command is "python3 ChemistryMatrix.py data/*.txt"<p>

<p>Each line of each text file is formatted as such: (player1 | player2 | player3 | player4 | player5 | Shots on Goal for | Missed Shots for | Scoring Opportunities for | Shots on Goal Against | Missed Shots Against | Scoring Opportunities Against) </p>


<h2>Output</h2>

<p>In this repository, there is a file called "Output.png". This file a boxplot that shows each players isolated impact on other players. In addition, there are other stats in standard output such as:</p>

<ul>
<li>Matrix with pairwise Corsi</li>
<li>Matrix with isolated impact</li>
<li>List of ordered pairwise isolated impact between players</li>
</ul>


<h2>Reuse<h2>

<p>When reusing the code, make sure to change the list of players as well as the threshold for the number of shifts for players to have together.  Each of these variables are global variables above main</p>
