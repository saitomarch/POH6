dict = Hash.new {|dict, key|
    dict[key] = []
}

gets.to_i.times do
    str = gets.chop
    dict[[str, str.reverse].min].push(str)
end

selfPalindromeWord = nil;

foundwords = []
revwords = []
words = dict.sort

words.each {|key , val|
    val.sort!
    idx = 0
    while idx < val.size / 2 and (val[idx] != val[val.size - (idx + 1)] or val[idx] == val[idx].reverse)
        foundwords.push(val[idx])
        revwords.push(val[val.size - (idx + 1)])
        idx += 1
    end
    if idx <= val.size - (idx + 1) and val[idx] == val[idx].reverse then
        selfPalindromeWord = (selfPalindromeWord and [val[idx], sameword].min) || val[idx]
    end
}

puts foundwords.join + (selfPalindromeWord || '') + revwords.reverse.join
