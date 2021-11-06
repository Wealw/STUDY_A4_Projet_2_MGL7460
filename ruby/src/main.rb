# frozen_string_literal: true

require_relative 'uptime'

begin
  file_data = File.read('uptime_file').split
  if file_data.length == 2
    u = Uptime.new
    puts u.generate_file_content(file_data[0].to_i.abs, file_data[1].to_i.abs)
  else
    puts "The file 'uptime_file' is badly formatted"
  end
rescue Errno::ENOENT
  puts 'There was a runtime error. File may be missing or it can be malformed'
end
