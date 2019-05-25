# GuzalAida

daemon配置
edit file: "/etc/rsyslog.conf" add 
```
#GuzalAida daemon log
local0.* /var/log/GuzalAida0
```
如果想要运行可以执行(默认为Release Version)
```
cd GuzalAida
chmod 0744 autorun.sh
./autorun.sh
```
