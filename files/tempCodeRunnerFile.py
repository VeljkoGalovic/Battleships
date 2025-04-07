from selenium import webdriver
from selenium.webdriver.common.by import By
from bs4 import BeautifulSoup
import time

link = input("Unesi link ka zadatku:\n") # PRIMER: https://en.grandgames.net/ships/id186282

driver = webdriver.Firefox()
driver.get(link)  # DODAJ ULAZ

time.sleep(7.5) # CEKANJE DA SE STRANICA UCITA

check_input = driver.find_element(By.XPATH, "//*[@id='timeradd_but']")
check_input.click()

time.sleep(2.5) # CEKANJE DA SE STRANICA UCITA
    
# UPISIVANJE U FAJL

html_content = driver.page_source  
driver.close()

soup = BeautifulSoup(html_content, "html.parser") 
print("TEST1")
with open(r"C:\Users\Administrator\Desktop\Battleships-main\Source.txt", "a", encoding="utf-8") as html_file:
    for line in soup.prettify():
        html_file.write(line)
print("TEST2")
html_file.close()
driver.quit()
