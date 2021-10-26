# frozen_string_literal: true

require 'date'



class Uptime
  public def convert_sec(sec)
    number_of_day = sec / 86_400
    number_of_hour = (sec - number_of_day * 86_400) / 3600
    number_of_min = (sec - number_of_day * 86_400 - number_of_hour * 3600) / 60
    [number_of_day, number_of_hour, number_of_min]
  end

  def format_current_hour
    t = Time.now
    "#{t.hour}:#{t.min}:#{t.sec}"
  end

  def format_day(number_of_day)
    case number_of_day
    when 0
      ''
    when 1
      '1 day, '
    else
      "#{number_of_day} days, "
    end
  end

  def format_hours_and_minutes(hour, minute)
    if hour.zero?
      "#{minute} min"
    elsif minute < 10
      "#{hour}:0#{minute}"
    else
      "#{hour}:#{minute}"
    end
  end

  def generate_file_content(up_time, idle_time)
    uptime_utility = Uptime.new

    current_hour = uptime_utility.format_current_hour

    converted_up_time = uptime_utility.convert_sec(up_time)
    converted_idle_time = uptime_utility.convert_sec(idle_time)

    up_days = uptime_utility.format_day(converted_up_time[0])
    idle_days = uptime_utility.format_day(converted_idle_time[0])

    up_hours_and_minutes = uptime_utility.format_hours_and_minutes(converted_up_time[1], converted_up_time[2])
    idle_hours_and_minute = uptime_utility.format_hours_and_minutes(converted_idle_time[1], converted_idle_time[2])

    "#{current_hour} up #{up_days}#{up_hours_and_minutes}\n#{current_hour} idle #{idle_days}#{idle_hours_and_minute}"
  end
end


