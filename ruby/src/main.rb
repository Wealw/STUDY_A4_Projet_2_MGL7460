# frozen_string_literal: true

require_relative 'uptime'

up_time = 3601
idle_time = 456_789

u = Uptime.new
puts u.generate_file_content(up_time, idle_time)
