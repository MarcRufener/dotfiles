#!/usr/bin/python3

import os
import subprocess

# Colors
blue  = "4"
green = "2" 

def run(arg):
  return subprocess.Popen(arg, stdout=subprocess.PIPE, stderr=subprocess.PIPE).stdout.read().decode(encoding="UTF-8")

def clearcolor():
  echo("\033[0m")

def echo(text):
  print(text, end='')

def color(text, clr):
  echo("\033[1;3" + clr + "m")
  echo(text)
  clearcolor()

def main():
  cal   = run(["cal"]).splitlines()
  dayow = run(["date", "+%a"])[:2]
  date  = run("date").split(" ")[2]
  month, year = list(filter(None, cal[0].split(" ")))

  print()
  echo(" " * (10 - len(month)//2 - 2))
  color(month, green)
  echo(" ")
  color(year, blue)
  print()

  before, after = cal[1].split(dayow)
  color(before, blue)
  color(dayow,  green)
  color(after,  blue)
  print()

  for e in cal[2:]:
    if date not in e: print(e)
    else:
      days_before, days_after = e.split(date)
      echo(days_before)
      color(date,  green)
      echo(days_after)
      print()

if __name__ == '__main__':
  main()
