#!/usr/bin/python3
"""Contains recursive api function"""
import collections
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

def count(subreddit, word_list):
    """Finds occurences of keywords in a subreddit
    """
    if subreddit is None:
        return None
    hot_list = recurse(subreddit)
    if hot_list is None:
        return None
    all_cnt = collections.Counter(hot_list)
    filtered = {}
    for word in word_list:
        word_l = word.lower()
        if all_cnt[word_l] > 0:
            if word in filtered:
                filtered[word] += filtered[word]
            else:
                filtered[word] = all_cnt[word_l]
    for keys, val in sorted(filtered.items(),
                       key=lambda item: item[1], reverse=True):
        print("{}: {}".format(keys, val))
    return filtered
 