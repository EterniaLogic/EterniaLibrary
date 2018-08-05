Generic Business Backend

This software was written for simulation systems and possibly for realtime use if adapted correctly by businesses.


DATABASE
This software is only a skeleton and does not currently have database capability unless a developer writes a wrapper.

REDUNDANCY
For an all-business backend like this, it is best to run and store information on at least 2 different servers.

SECURITY
Security is panamount for a program like this.
Do not run it on a windows server, since this is only a backend. and Windows servers can get Trojans which can sniff your server memory and network.
Have a consult security specialists if a company does not want to lose sensitive customer data.
Passwords shoud be hashed.
Credit Card numbers, SSN and other private information should be encrypted using at least AES256 before being encoded into HEX in a database.
This code should only run on the intranet for a company.
