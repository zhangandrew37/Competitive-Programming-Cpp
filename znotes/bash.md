## Pipe

commandA | command B

- first execute command A and use output as input of command B

```head -n11 file3.txt | tail -n2```

- displays lines 10 and 11 of file3.txt
  
## Bash Script

```bash
#!/bin/bash
# Answers whether a candidate word might be a good password
usage () {
    echo "Usage: ${0} password" >&2
    exit 1
}
if [ ${#} -ne 1 ]; then
    usage
fi
    #matches beginning of string
    egrep "^${1}$" /usr/share/dict/words > /dev/null
if [ ${?} -eq 0 ]; then
    echo Not a good password
else
    echo May be a good password
fi
```

```bash
# for every word in file
counter = 0
for word in $(cat "${2}"); do
    if [${word} == "${1}" ]; then
        count=$((counter + 1))
    fi
done
echo ${counter}
```