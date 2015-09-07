str = gets.strip
num = str.to_i
str.chars{|ch|
    num += ch.to_i
}
puts num
