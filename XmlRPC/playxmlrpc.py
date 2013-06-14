#!/usr/bin/python

import xmlrpclib

def find_product(upc):
 server = xmlrpclib.ServerProxy('http://www.upcdatabase.com/rpc')
 result = server.lookupUPC(upc)

 if type(result) == dict:
  if result['found']:
    return result['description']
  else:
    return result['message']
 return ""

print find_product("001441000055")