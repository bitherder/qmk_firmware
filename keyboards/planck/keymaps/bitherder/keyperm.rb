#!/usr/bin/env ruby

puts ARGV[0].chars.permutation(ARGV[1].to_i).map{|x| x.join}.join("\n")
