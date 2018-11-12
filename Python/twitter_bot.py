#!/usr/bin/env python
# -*- coding: utf-7 -*-
import tweepy, time, sys

#argfile = str(sys.argv[1])

CONSUMER_KEY = '1stHclGYUG4tOysxqyBc4QFO4'
CONSUMER_SECRET = 'o65ylir1pyw9fH7vpyICm0jmxx2tzlZ0kge9SPhcqiXAAGmGMF'
ACCESS_KEY = '1306806691-hj3O8tWaviXz84UiRfLcwGrLGFBnnRdSz7jlApK'
ACCESS_SECRET = 'xWwwepU5vmSxj1R21CE2I3Fe9o8V4ezQIauFiBqgu7z06'
auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)
api = tweepy.API(auth)

firsttweet = "hey guys im streaming at https://Twitch.tv/CreepyTrash"
secondtweet = "still @ it, come check out the stream https://Twitch.tv/Creepytrash"

results = api.search(q="warZ")

for line in results:
    print line.text


api.update_status(status = firsttweet)
time.sleep(900) #Delay thread 15 minutes
time.sleep(900) #Delay thread 15 minutes
time.sleep(900) #Delay thread 15 minutes
#45 minutes before 2nd tweet
api.update_status(status = secondtweet)
sys.exit()
filename.close()
