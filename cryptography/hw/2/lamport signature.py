import hashlib
import math
import secrets
import sys

char_enc = "utf-8"
byte_order = sys.byteorder
row = 2
col = 256

# generate a keypair for a one-time signature
def keygen():
    sk = [[0] * col for _ in range(row)]
    pk = [[0] * col for _ in range(row)] 
    for i in range(0, row):
        for j in range(0, col):
            sk[i][j] = secrets.token_bytes(32) # return a random byte string containing nbytes number of bytes
            pk[i][j] = hashlib.sha256(sk[i][j]).digest() # message digest is a cryptographic hash function containing a string of digits created by a one-way hashing formula
    keypair = [sk, pk]
    return keypair

# sign message using lamport one-time signature
def sign(m, sk):
    sig = [0] * col
    h = int.from_bytes(hashlib.sha256(m.encode(char_enc)).digest(), byte_order)
    for i in range(0, col):
        b = h >> i & 1
        sig[i] = sk[b][i]
    return sig

# verify lamport message signature
def verify(m, sig, pk):
    h = int.from_bytes(hashlib.sha256(m.encode(char_enc)).digest(), byte_order)
    for i in range(0, col):
        b = h >> i & 1
        check = hashlib.sha256(sig[i]).digest()
        if pk[b][i] != check:
            return False
    return True

keypair = keygen()
message = "lamport signature"
sig = sign(message, keypair[0])
print(verify(message, sig, keypair[1]))
