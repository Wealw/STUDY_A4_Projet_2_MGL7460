# frozen_string_literal: true

require 'minitest/autorun'
require_relative '../src/uptime'

class UptimeTest < Minitest::Test
  def setup
    @uptime_utility = Uptime.new
  end

  def test_convert_sec
    lambda {
      sec = 777_600 # 9 days
      assert_equal @uptime_utility.convert_sec(sec), [9, 0, 0]
    }.call

    lambda {
      sec = 54_000 # 15 hours
      assert_equal @uptime_utility.convert_sec(sec), [0, 15, 0]
    }.call

    lambda {
      sec = 3599 # 59 minutes
      assert_equal(@uptime_utility.convert_sec(sec), [0, 0, 59])
    }.call

  end

  def test_format_day
    lambda {
      number_of_days = 0
      assert_equal @uptime_utility.format_day(number_of_days), ''
    }.call

    lambda {
      number_of_days = 1
      assert_equal @uptime_utility.format_day(number_of_days), '1 day, '
    }.call

    lambda {
      number_of_days = 20
      assert_equal @uptime_utility.format_day(number_of_days), '20 days, '
    }.call
  end

  def test_format_hours_and_minutes
    lambda {
      number_of_hour = 0
      number_of_minute = 0
      assert_equal @uptime_utility.format_hours_and_minutes(number_of_hour, number_of_minute), '0 min'
    }.call

    lambda {
      number_of_hour = 7
      number_of_minute = 5
      assert_equal @uptime_utility.format_hours_and_minutes(number_of_hour, number_of_minute), '7:05'
    }.call

    lambda {
      number_of_hour = 17
      number_of_minute = 20
      assert_equal @uptime_utility.format_hours_and_minutes(number_of_hour, number_of_minute), '17:20'
    }.call
  end

  def test_generate_file_content
    lambda {
      up_sec = 86461 # 1 day 00:01:01.
      idle_sec = 23456789 # 271 days 11:46:29.
      assert_match('1 day, 1 min', @uptime_utility.generate_file_content(up_sec, idle_sec))
      assert_match('271 days, 11:46', @uptime_utility.generate_file_content(up_sec, idle_sec))
    }.call

    lambda {
      up_sec = 4567 # 01:16:07.
      idle_sec = 4056 # 01:07:36.
      assert_match('1:16', @uptime_utility.generate_file_content(up_sec, idle_sec))
      assert_match('1:07', @uptime_utility.generate_file_content(up_sec, idle_sec))
    }.call
  end
end
