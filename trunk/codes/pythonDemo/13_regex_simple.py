#!/usr/bin/python
#.*
#.*?
#\d
#\w
#.+
#\s
#\S
#()
#^
#$
import re
orig_string = 'This is a string with field (1)="f1" and (2)="f2" and (3)="f3" and boundary is "<>"'
regexp_greedy = r'^.*with field\s*\(\d+\)\s*=\s*"(?P<field1>\w+)".*\(\d+\)\s*=\s*"(?P<field2>\w+)".*is.*(?P<field3>"\S+").*$'
pattern = re.compile(regexp_greedy)

#match the whole string, then get specified substring.
match = pattern.match(orig_string)

if None == match:
    print "Not match."
    exit(1)
#the whole string
print "Whole string is:"
print match.group(0)

#refer group in "()" by group number:
print "group 1:"
print match.group(1)
#refer group by group name.
print "group field1:"
print match.group("field1")

# default greedy('.*' match as long as possible) so it is "f3" not "f2"
print "greedy group 2:"
print match.group(2)
#refer group by group name.
print "greedy group field2:"
print match.group("field2")

# nogreedy search('.*?' match not as long as possible) for "f2"
regexp_nogreedy = r'^.*with field\s*\(\d+\)\s*=\s*"(?P<field1>\w+)".*?\(\d+\)\s*=\s*"(?P<field2>\w+)".*is.*(?P<field3>"\S+").*$'
pattern = re.compile(regexp_nogreedy)
match = pattern.match(orig_string)
print "nogreedy group 2:"
print match.group(2)
#refer group by group name.
print "nogreedy group field2:"
print match.group("field2")

#match a substring and return the position.
#sub_str = orig_string[10:30]
#print match.start(0)
#match = pattern.search('hello world!')

#p = re.compile(r'\d+')
#print p.split('one1two2three3four4')

#m = re.match(r'hello', 'hello world!')
