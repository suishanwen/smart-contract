
基于高性能区块链网络(EOS)开发去中心化应用

http://bitcoinrobot.cn/#/note?source=sw&thread=95


cleos wallet unlock -n suishanwen

eosiocpp -o eosio.token2.wast eosio.token2.cpp

eosiocpp -g eosio.token2.abi eosio.token2.cpp


cleos set contract bitcoinrobot ~/Documents/smart-contract/empty -p bitcoinrobot@active

cleos set contract bitcoinrobot ~/Documents/smart-contract/msg -p bitcoinrobot@active

cleos set contract bitcoinrobot ~/Documents/smart-contract/hello -p bitcoinrobot@active

cleos set contract bitcoinrobot ~/Documents/smart-contract/table -p bitcoinrobot@active

cleos set contract bitcoinrobot ~/Documents/smart-contract/note -p bitcoinrobot@active

cleos set contract bitcoinrobot ~/Documents/smart-contract/eosio.token -p bitcoinrobot@active

cleos set contract bitcoinrobot ~/Documents/smart-contract/eosio.token2 -p bitcoinrobot@active


--hi

cleos push action bitcoinrobot hi '["bitcoinrobot","hello"]' -p bitcoinrobot

--table

cleos push action bitcoinrobot version '' -p bitcoinrobot

cleos get table bitcoinrobot bitcoinrobot poll

cleos get table bitcoinrobot bitcoinrobot pollvotes

cleos push action bitcoinrobot addpoll '["sw","投票1"]' -p bitcoinrobot

cleos push action bitcoinrobot rmpoll '["sw","投票1"]' -p bitcoinrobot

cleos push action bitcoinrobot status '["投票1"]' -p bitcoinrobot

cleos push action bitcoinrobot statusreset '["投票1"]' -p bitcoinrobot

cleos push action bitcoinrobot addpollopt '["投票1","A"]' -p bitcoinrobot

cleos push action bitcoinrobot addpollopt '["投票1","B"]' -p bitcoinrobot

cleos push action bitcoinrobot addpollopt '["投票1","C"]' -p bitcoinrobot

cleos push action bitcoinrobot rmpollopt '["投票1",""]' -p bitcoinrobot

cleos push action bitcoinrobot vote '["投票1","A","user1"]' -p bitcoinrobot

cleos push action bitcoinrobot vote '["投票1","A","user2"]' -p bitcoinrobot

cleos push action bitcoinrobot vote '["投票1","B","user3"]' -p bitcoinrobot

--note

cleos get table bitcoinrobot bitcoinrobot note


--eosio.token

cleos get table bitcoinrobot bitcoinrobot accounts

cleos get table bitcoinrobot allinbitcoin accounts

cleos get table bitcoinrobot SW stat

cleos get table bitcoinrobot UZI stat



cleos push action bitcoinrobot  create '{"issuer":"bitcoinrobot", "maximum_supply":"7777.7777 UZI"}' -p bitcoinrobot

cleos push action bitcoinrobot   issue  '[ "bitcoinrobot", "7777.0000 SW", "memo"  ]' -p bitcoinrobot

cleos push action bitcoinrobot   issue  '[ "bitcoinrobot", "7777.7777 UZI", "memo"  ]' -p bitcoinrobot

cleos push action bitcoinrobot transfer '[ "bitcoinrobot", "allinbitcoin", "1.0000 SW", "memo"  ]'  -p bitcoinrobot

cleos push action bitcoinrobot transfer '[ "bitcoinrobot", "bitcoinrobot", "0.0001 SW", "memo"  ]'  -p bitcoinrobot


cleos push action bitcoinrobot transfer '[ "allinbitcoin", "bitcoinrobot", "0.0001 SW", "memo"  ]'  -p allinbitcoin

cleos push action bitcoinrobot burn '[ "allinbitcoin", "0.0001 SW" ]'  -p bitcoinrobot

cleos push action bitcoinrobot burnitall '["bitcoinrobot","UZI"]'  -p bitcoinrobot

cleos push action bitcoinrobot refund '["bitcoinrobot","0.0001 UZI"]'  -p bitcoinrobot
