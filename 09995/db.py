# coding: utf-8
import requests
from urllib.request import urlopen
from bs4 import BeautifulSoup

poke = list()
poke_skill = list()
SZ = 151

def poke_list_crawling():
	global poke
	global SZ
	URL = "https://pokemondb.net/pokedex/all"
	headers = {'User-Agent': 'Mozilla/5.0'} # like web browser
	res = requests.get(URL, headers=headers)
	bsObj = BeautifulSoup(res.text, "html.parser")
	poke_list = bsObj.find_all("a","ent-name")
	bf = -1
	for i in poke_list:
		li = str(i).replace('#', ' ').split()
		if bf == int(li[6]):
			continue
		if int(li[6])>SZ:
			break
		bf = int(li[6])
		print (i.get_text().replace('♀','-f').replace('♂','-m'))
		poke.append(i.get_text().replace('♀','-f').replace('♂','-m').replace('. ','-').replace('\'',''))

	print(len(poke))

def poke_skill_crawling(sz):
	global poke
	global poke_skill

	for ith in range(0, sz):
		#print(ith)
		print(poke[ith])
		URL = "https://pokemondb.net/pokedex/"+ poke[ith] + "/moves/3"
		headers = {'User-Agent': 'Mozilla/5.0'} # like web browser
		res = requests.get(URL, headers=headers)
		bsObj = BeautifulSoup(res.text, "html.parser")

		skill_list = bsObj.find_all("table","data-table")
		# HM number
		HM_list = [0]
		ck = 0
		if "not learn any moves" in str(bsObj):
			ck -= 1
		if "Pre-evolution" in str(bsObj):
			ck += 1

		if len(skill_list) >= 3:
			if str(bsObj).count('not learn any HMs') == 0:
				for i in skill_list[2+ck]:
					li = i.find_all("td","cell-num")
					idx = 0
					for j in li:
						if idx % 3 == 0:
							HM_list.append(j.get_text())
						idx+=1
		## TM number
		TM_list = [0]
		if len(skill_list) >= 4:
			if str(bsObj).count('not learn any HMs') < 6  :
				if str(bsObj).count('not learn any HMs') == 3:
					ck -= 1
				for i in skill_list[3+ck]:
					li = i.find_all("td","cell-num")
					idx = 0
					for j in li:
						if idx % 3 == 0:
							TM_list.append(j.get_text())
						idx+=1
		#print(HM_list,TM_list)
		poke_skill.append([HM_list, TM_list])

def file_making():
	global SZ
	global poke_skill
	f = open('pokemon.txt', 'w', encoding='utf8')
	for i in range(0,SZ):
		print(i)
		hm_ck = [0]*9
		for j in poke_skill[i][0]:
			hm_ck[int(j)] = 1;
		tm_ck = [0]*51
		for j in poke_skill[i][1]:
			tm_ck[int(j)] = 1;
		HM_str, TM_str = "", ""
		for j in range(1, 9):
			HM_str += str(hm_ck[j])
		for j in range(1, 51):
			TM_str += str(tm_ck[j])
		print(poke[i] +HM_str + TM_str)
		f.write("\"" + HM_str + TM_str + "\",\n")
	f.close()

poke_list_crawling()
poke_skill_crawling(SZ)
file_making()
