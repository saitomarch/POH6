numOfCells = gets.to_i
goal = numOfCells - 1
cells = gets.strip.split(" ")

CURRENT = 0
FINISHED = 1
DEAD = 2

gets.to_i.times {
    actNum = gets.to_i
    moveLog = Array.new

    status = CURRENT

    while status == CURRENT do
        if actNum == goal then
            status = FINISHED
        elsif actNum < 1 || goal < actNum then
            status = DEAD
        else
            moves = cells[actNum].to_i
            if moves == 0 then
                status = DEAD
            else
                actNum += moves
                moveLog.each {|movedNum|
                    if actNum == movedNum then
                        status = DEAD
                        break
                    end
                }
                if status != DEAD then
                    moveLog.push(actNum)
                end
            end
        end
    end
    puts status == FINISHED ? "Yes" : "No"
}
