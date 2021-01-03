Language="None"
Year="None"
Day="None"

if [ $# != 3 ]
then
	echo "Usage: ./Start.sh [Language] [Year] [Day]"
	exit
fi

# Thi will do for now, but a better approach would be to get all folders  by name as they represent the langauges used, insted of manual typing each of them
if [ $1 = "Python" ] || [ $1 = "C" ]
then
	Language=$1
else
	echo "Available languages are : Python, C"
	exit
fi

if [ $2 -lt 2015 ] || [ $2 -gt 2020 ]
then
	echo "Invalid year. Available years are : 2015, 2016, 2017, 2018, 2019, 2020"
	exit
else
	Year=$2
fi

if [ $3 -lt 1 ] || [ $3 -gt 25 ]
then
	echo "Invalid day. Valid days range from 1 to 25"
	exit
else
	Day="day_"$(printf "%02d" $3)
fi

mkdir -p $Language/$Year/$Day

cd $Language/$Year/$Day

touch p1.py p2.py

curl --cookie ~/aoc_cookies.txt -o input \https://adventofcode.com/$Year/day/$(printf "%d" $3)/input
