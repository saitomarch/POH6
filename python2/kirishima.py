numOfCells = int(raw_input())
goal = numOfCells - 1
cells = raw_input().strip().split(" ")

CURRENT = 0
FINISHED = 1
DEAD = 2

for idx in range(0, int(raw_input())):
    actNum = int(raw_input())
    moveLog = []
    status = CURRENT
    while status == CURRENT:
        if actNum == goal:
            status  = FINISHED
        elif actNum < 1 or goal < actNum:
            status = DEAD
        else:
            moves = int(cells[actNum])
            if moves == 0:
                status = DEAD
            else:
                actNum += moves
                for movedNum in moveLog:
                    if actNum == movedNum:
                        status = DEAD
                        break
                if status != DEAD
                    moveLog.append(actNum)
    print ("Yes" if status == FINISHED else "No")
