
基于高性能区块链网络(EOS)开发去中心化应用
http://bitcoinrobot.cn/#/note?source=sw&thread=95


cleos wallet unlock -n suishanwen
PW5JVWjru985gLUvPoA5oXAuKNjqV3aqx4dttumTwWzyxRybE6GPn
eosiocpp -o eosio.token2.wast eosio.token2.cpp
eosiocpp -g eosio.token2.abi eosio.token2.cpp


cleos set contract bitcoinrobot ~/Documents/smart-contract/empty -p bitcoinrobot@active
cleos set contract bitcoinrobot ~/Documents/smart-contract/msg -p bitcoinrobot@active
cleos set contract bitcoinrobot ~/Documents/smart-contract/hello -p bitcoinrobot@active
cleos set contract bitcoinrobot ~/Documents/smart-contract/table -p bitcoinrobot@active
cleos set contract bitcoinrobot ~/Documents/smart-contract/note4sw -p bitcoinrobot@active
cleos set contract bitcoinrobot ~/Documents/smart-contract/curd -p bitcoinrobot@active
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
cleos push action bitcoinrobot create '["今天天气真好！"]' -p bitcoinrobot
cleos push action bitcoinrobot update '[0,"明天天气会更好！"]' -p bitcoinrobot
cleos push action bitcoinrobot del '[0]' -p bitcoinrobot

cleos push action bitcoinrobot c '["sw","The fabric of the cosmos","<div>PBS纪录片《宇宙的构造》，豆瓣评分9.5。共四个部分，以一种酷炫的方式展示了空间、时间、量子跃迁、多重宇宙方面的科普知识，极富视觉冲击力。<br>\n    <br>\n    <a href=\"http://weibo.com/1888861417/Da3Y6tr6B?type=comment#_rnd1451040581488\" target=\"blank\">\n        微博上的介绍</a><br>\n    <br>\n    <br>\n    PBS：NOVA：《宇宙的构造》（全四集）（中英双语字幕）<br>\n    <br>\n    <p><a href=\"http://www.bilibili.com/video/av1935063/index_1.html\" target=\"blank\"\">\n\n        第一集：无限空间</a>&nbsp;</p>\n    <p><br>\n    </p>\n    <p><a href=\"http://www.bilibili.com/video/av1935063/index_2.html\" target=\"blank\">第二集：时间幻象</a> &nbsp;</p>\n    <p><br>\n    </p>\n    <p><a href=\"http://www.bilibili.com/video/av1935063/index_3.html\" target=\"blank\">第三集：量子跃迁</a> &nbsp;</p>\n    <p><br>\n    </p>\n    <p><a href=\"http://www.bilibili.com/video/av1935063/index_4.html\" target=\"blank\">第四集：多重宇宙&nbsp;</a></p></div>","198.181.57.231","","",0]' -p bitcoinrobot
cleos push action bitcoinrobot r '[0]' -p bitcoinrobot
cleos push action bitcoinrobot u '[0,"The fabric of the cosmos","<div>PBS纪录片《宇宙的构造》，豆瓣评分9.5。共四个部分，以一种酷炫的方式展示了空间、时间、量子跃迁、多重宇宙方面的科普知识，极富视觉冲击力。<br>\n    <br>\n    <a href=\"http://weibo.com/1888861417/Da3Y6tr6B?type=comment#_rnd1451040581488\" target=\"blank\">\n        微博上的介绍</a><br>\n    <br>\n    <br>\n    PBS：NOVA：《宇宙的构造》（全四集）（中英双语字幕）<br>\n    <br>\n    <p><a href=\"http://www.bilibili.com/video/av1935063/index_1.html\" target=\"blank\"\">\n\n        第一集：无限空间</a>&nbsp;</p>\n    <p><br>\n    </p>\n    <p><a href=\"http://www.bilibili.com/video/av1935063/index_2.html\" target=\"blank\">第二集：时间幻象</a> &nbsp;</p>\n    <p><br>\n    </p>\n    <p><a href=\"http://www.bilibili.com/video/av1935063/index_3.html\" target=\"blank\">第三集：量子跃迁</a> &nbsp;</p>\n    <p><br>\n    </p>\n    <p><a href=\"http://www.bilibili.com/video/av1935063/index_4.html\" target=\"blank\">第四集：多重宇宙&nbsp;</a></p></div>","198.181.57.231","","",1]' -p bitcoinrobot
cleos push action bitcoinrobot d '["bitcoinrobot",0]' -p bitcoinrobot


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

cleos push action bitcoinrobot burnitall '["bitcoinrobot","0.0001 UZI"]'  -p bitcoinrobot

cleos push action bitcoinrobot refund '["bitcoinrobot","0.0001 UZI"]'  -p bitcoinrobot


cleos transfer bitcoinrobot huobideposit "40.0000 EOS" "482646"  -p bitcoinrobot
