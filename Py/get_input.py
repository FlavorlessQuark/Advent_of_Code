import requests
import collections
import os
import re
from getpass import getpass

########### Login user ##############
if not os.environ.get("CDB_UNAME"):
	print("Set CDB_UNAME or type username")
	print("Username :")
	uname = input()
else:
	uname = os.environ.get("CDB_UNAME")
if not os.environ.get("CDB_PASS"):
	print("Set CDB_PASS or type password")
	pw = getpass()
else:
	pw = os.environ.get("CDB_PASS")

Session = requests.Session()
data = {
       "uname":uname,
       "pw":pw,
}

lang = input()
print("Day : ")
day = input()
print("Year" : ")
year = input()

if not str.isdigit(day) or not str.isdigit(year):
	exit()
url = "https://adventofcode.com/" + year + "/day/" + day + "/input"

r = Session.post(url, data=data)

login_response = r.text
if login_response.find("Failed to login") != -1:
	print("~ Failed to login  ~")
	exit()
else:
	print("~ Login successful ~")

response = Session.get(url)
print(response)
############## Setup ############

directory = os.getcwd()
directory += "/cdb"

if not os.path.isdir(directory):
	os.mkdir(directory)

with open('config/problem_ids') as input:
	ids = [int(line) for line in input]

############# Download ##########

for pids in ids:
