lineStr = gets.chop
words = []
for line in 0...lineStr.to_i do
    words.push(gets.chop)
end

words.sort

found = []
revWords = []
selfPalindromeWord = ""
for word in words do
    if !revWords.include?(word) and word != selfPalindromeWord then
        for revWord in words do
            if word == revWord.reverse then
               if word == revWord and words.count(word).modulo(2) == 1 then
                   selfPalindromeWord = word
                   selfPalindromeCount = words.count(word)
               else
                   found.push(word)
                   revWords.push(revWord)
               end
            end
        end
    end
end

str = found.join

if ! selfPalindromeWord.empty? and selfPalindromeCount > 0 then
    for idx in 0... selfPalindromeCount do
        str += selfPalindromeWord
    end
end

str += revWords.reverse.join

puts str
