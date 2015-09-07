numOfCells = int(raw_input())
goal = numOfCells - 1
cells = raw_input().strip().split(" ")

for idx in range(0, int(raw_input())):
    actNum = int(raw_input())
    moveLog = []
    finished = False
    dead = False
    while finished == False and dead == False:
        if actNum == goal:
            finished = True
        elif actNum < 1 or goal < actNum:
            dead = True
        else:
            moves = int(cells[actNum])
            if moves == 0:
                dead = True
            else:
                actNum += moves
                for movedNum in moveLog:
                    if actNum == movedNum:
                        dead = True
                if dead == False:
                    moveLog.append(actNum)
    print ("Yes" if finished else "No")
