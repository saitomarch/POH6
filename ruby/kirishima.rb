numOfCells = gets.to_i
goal = numOfCells - 1
cells = gets.strip.split(" ")

gets.to_i.times {
    actNum = gets.to_i
    moveLog = Array.new
    finished = dead = false
    while !finished && !dead do
        if actNum == goal then
            finished = true
        elsif actNum < 1 || goal < actNum then
            dead = true
        else
            moves = cells[actNum].to_i
            if moves == 0 then
                dead = true
            else
                actNum += moves
                moveLog.each {|movedNum|
                    if actNum == movedNum then
                        dead = true
                        break
                    end
                }
                if !dead then
                    moveLog.push(actNum)
                end
            end
        end
    end
    puts finished ? "Yes" : "No"
}
