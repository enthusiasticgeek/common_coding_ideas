#!/usr/bin/env python3
# Using the requests module from Python's standard library
import requests

# Make an HTTP GET request
response = requests.get("https://api.openai.com")

# Print the response status code
print(response.status_code)
