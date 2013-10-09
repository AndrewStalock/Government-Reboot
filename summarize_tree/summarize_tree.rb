#!/usr/bin/ruby
require 'find'

num_dir = 0
num_regular = 0

Find.find(ARGV[0]) do |path|
  if FileTest.directory?(path)
    num_dir += 1

  else FileTest.file?(path)
    num_regular += 1
 end
end

puts "Processed all the files from <"+ ARGV[0] + ">."
puts "There were " + num_dir.to_s + " directories."
puts "There were " + num_regular.to_s + " regular files."
