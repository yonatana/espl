import sys
import csv
#open file
reader = csv.reader(open('grades.csv','rb'))
reader.next()
#do mission

dict={}
for row in reader:
  #a = line.split(',')
  grade = row[-1]
  id = row[0]
  if grade not in dict:
    dict[grade] = [id]
  else:
    dict[grade].append(id)

for key in dict.viewkeys():

  print 'score: ',key.strip(),'count  ',len(dict[key])
  print "students:", dict[key]
print "hell yea!"

