#!/usr/bin/python3
"""Contains recursive api function"""
import requests


def recurse(subreddit, hot_list=[], after=""):
    if subreddit is None:
        return None
    response = requests.get("https://reddit.com/r/{}/hot.json?after={}".
                            format(subreddit, after),
                            headers={"User-agent": "Kenneth"})

    if response.status_code != 200:
        return None
    if after is None:
        return hot_list
    else:
        posts = response.json().get("data").get("children")
        for idx in posts:
            titles = idx.get("data").get("title")
            hot_list.append(titles)
        after = response.json().get("data").get("after")
        return recurse(subreddit, hot_list, after)
