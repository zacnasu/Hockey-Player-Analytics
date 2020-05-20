#!/usr/bin/env python3

import sys
import fileinput
import numpy as np
import math
import matplotlib.pyplot as plt

#list containing jersey numbers of players in order
rosterIndex = [3,5,6,7,8,11,12,14,15,16,17,18,19,21,22,23,27,71,88,91]


def main():
    team_size = len(rosterIndex)

    #intializing matrices that hold data
    shiftMatrix = np.zeros((team_size,team_size),dtype = int)
    shotAttemptsForMatrix = np.zeros((team_size,team_size),dtype = float)
    shotAttemptsAgainstMatrix = np.zeros((team_size,team_size),dtype = float)
    corsiMatrix = np.zeros((team_size,team_size),dtype = float)
    isolatedImpact = np.zeros((team_size,team_size),dtype = int)

    #reading files given to program
    num_files = len(sys.argv)
    fileLines = []
    for i in range(1,num_files):
        try:
            fileptr = open(sys.argv[i], 'r')
        except FileNotFoundError:
            print("Invalid Input File " + sys.argv[i])
            sys.exit(1)
        [fileLines.append(line) for line in fileptr]

    #splits file lines into a 2d matrix
    nonZeroShifts = splitLines(fileLines)

    #totals up data for each pair of players and adds them to shotAttemptsForMatrix and shotAttemptsAgainstMatrix to later be used
    for shift in nonZeroShifts:
        player = []
        player.append(getIndex(shift[0]))
        player.append(getIndex(shift[1]))
        player.append(getIndex(shift[2]))
        player.append(getIndex(shift[3]))
        player.append(getIndex(shift[4]))
        for p1 in player:
            if p1!=None:
                for p2 in player:
                    if p2!= None:
                        shiftMatrix[p1][p2] +=1

                        shotAttemptsForMatrix[p1][p2] += shift[5]+shift[6]
                        shotAttemptsAgainstMatrix[p1][p2] += shift[8]+shift[9]

    #caclulates Corsi for each pair of players
    for i in range(0,team_size):
        for j in range(0,team_size):
            if shiftMatrix[i][j] > 20:
                corsiMatrix[i][j] = int(100*(shotAttemptsForMatrix[i][j]/(shotAttemptsAgainstMatrix[i][j]+shotAttemptsForMatrix[i][j])))
            else:
                corsiMatrix[i][j] = None
    print(corsiMatrix)


    #calculates impact through players together vs their individual averages
    for i,line in enumerate(corsiMatrix):
        for j, elem in enumerate(line):
            if not math.isnan(elem):
                isolatedImpact[i][j] = corsiMatrix[i][j] - corsiMatrix[j][j]
    print(isolatedImpact)

    #creates boxplot
    plt.boxplot(isolatedImpact, labels = rosterIndex)
    plt.title("Player Isolated Impact")
    plt.ylabel("Percent Impact")
    plt.xlabel("Player Numbers")
    plt.show()

    #Shows pairwise Chemistry between each pair of players
    chemistryLi = []
    for i in range(team_size):
        for j in range(i-1):
            chemistryLi.append((rosterIndex[i],rosterIndex[j],isolatedImpact[i][j]+isolatedImpact[j][i],shiftMatrix[i][j],shotAttemptsForMatrix[i][j]+shotAttemptsAgainstMatrix[i][j]))
    chemistryLi.sort(key = takeThird)
    for elem in chemistryLi:
        print(elem)

#function used as key to sort pairwise chemistry numbers
def takeThird(elem):
    return elem[2]

#gets index of the array based upon jersey number
def getIndex(number):
    try:
        return rosterIndex.index(number)
    except ValueError:
        return None

#turns each line into a list of ints and also cleans data
def splitLines(fileLines):
    shiftlines = []
    for line in fileLines:
        tempLine = line.split()
        tempLine = [int(elem) for elem in tempLine]
        if len(tempLine) == 11:
            if not checkZero(tempLine):
                shiftlines.append(tempLine)
    return shiftlines

#checks if the values
def checkZero(li):
    return (li[5] == 0 and li[6] == 0 and li[7] == 0 and li[8] == 0 and li[9] == 0 and li[10] == 0)

if __name__ == "__main__":
    main()
