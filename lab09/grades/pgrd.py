import sys
import csv
#open file
reader = csv.reader(open('grades.csv','rb'))
reader.next()
#do mission
avg =0
sum=0
for row in reader:
  avg = avg + float(row[2])
  sum = sum + 1
  print row
print "the avg is: " ,(float(avg/sum))


