#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define DEBUG 



/***************元素設定*********************/
struct question{
	char *Q;
	int isq;
	char *A1;
	char *A2;
	char *A3;
	char *A4;
	int next[4];
};

struct question nQ[15];

int reset(void)
{
	int i=1;
/*	for(i=1;i<15;i++)
	{
		nQ[i].Q=(char*)calloc(50,sizeof(char));
		nQ[i].A1=(char*)calloc(50,sizeof(char));
		nQ[i].A2=(char*)calloc(50,sizeof(char));
		nQ[i].A3=(char*)calloc(50,sizeof(char));
		nQ[i].A4=(char*)calloc(50,sizeof(char));
	}
*/	
	nQ[1].Q="1、在討論區中，如果有人對你所發表的言論大力吐槽，甚至口出惡言，你的反應會是：";
	nQ[1].A1="A、大家都有言論自由，隨便他！";
	nQ[1].A2="B、心�媔W不爽，不過還是得維持風度，留言請他自重好了。";
	nQ[1].A3="C、搞什麼？居然敢罵我，當然一定要罵回去！";
	nQ[1].A4="D、撂兄弟，叫網友在網路上一起圍剿他。";
	for(i=0;i<4;i++)
		nQ[1].next[i]=i+2;
	nQ[1].next[3]=2;
	nQ[1].isq=1;
	
	nQ[2].Q="2、 在KTV歡唱得正high時，麥克風突然失靈了，聲音忽有忽滅，氣氛馬上冷了下來，這時你會：";
	nQ[2].A1="A、應該是線路有問題，大家趕快動手檢查看看。";
	nQ[2].A2="B、誰？是誰在搞鬼？一定是在場的人故意搗亂！";
	nQ[2].A3="C、馬的！叫服務人員來，我要客訴！";
	nQ[2].A4="D、算了，不唱了，真掃興。";
	nQ[2].isq=1;
	nQ[2].next[0]=3;
	nQ[2].next[1]=5;
	nQ[2].next[2]=4;
	nQ[2].next[3]=6;
	
	nQ[3].Q="3、 一陣子沒聯絡的朋友最近出手變得很大方，和他出去老是喜歡買單請客，你的態度會是？";
	nQ[3].A1="A、哇！有個有錢的朋友真好！以後一定要好好保持聯絡。";
	nQ[3].A2="B、坦白問他：你是不是中樂透了？";
	nQ[3].A3="C、感覺有點討厭，大家做朋友幹嘛要搞階級，你是看我窮是吧？";
	nQ[3].A4="D、搞不好他是做了什麼見不得人的勾當，還是保持距離比較妥當。";
	nQ[3].isq=1;
	nQ[3].next[0]=5;
	nQ[3].next[1]=6;
	nQ[3].next[2]=5;
	nQ[3].next[3]=6;
	
	nQ[4].Q="4、 和某個網友相談甚歡，決定約出來見見面聊聊天，但為了保險起見，還是約在公共場所見面比較安全，這時你會：";
	nQ[4].A1="A、興高採烈，當然要穿戴整齊準時赴約！";
	nQ[4].A2="B、怕對方找不到，我還是先到約定地點等著好了。";
	nQ[4].A3="C、不怕一萬，只怕萬一，如果對方是恐龍怎辦？還是在旁邊先驗驗貨色再決定要不要現身。";
	nQ[4].A4="D、沒什麼好躲躲藏藏的，能準時到就準時到吧！";
	nQ[4].isq=1;
	nQ[4].next[0]=5;
	nQ[4].next[1]=5;
	nQ[4].next[2]=6;
	nQ[4].next[3]=3;
	
	nQ[5].Q="5、 今天網咖�堛漱H超多，位置只剩下螢幕面向外邊的那一個，來往行人對螢幕�堛漱漁e一覽無遺，這時你會選擇：";
	nQ[5].A1="A、隨便啦！有得玩比較重要！";
	nQ[5].A2="B、那麼爛的位置誰要坐！換家啦！";
	nQ[5].A3="C、既然進來了，實在不好意思說不要，忍耐一個小時好了。";
	nQ[5].A4="D、這個位置不錯啊！反正我又不怕人看，坐哪�埵酗偵艤鰜Y？";
	nQ[5].isq=1;
	nQ[5].next[0]=6;
	nQ[5].next[1]=7;
	nQ[5].next[2]=7;
	nQ[5].next[3]=8;
	
	nQ[6].Q="6、 和心�埵麻I喜歡的人出去喝咖啡，氣候涼爽宜人，氣氛正好，點單時，店員的態度卻十分惡劣，這時你會：";
	nQ[6].A1="A、心想：這家店的服務態度真差，下次打死我也不來了！";
	nQ[6].A2="B、搞什麼！態度這麼差，我也不會給你好臉色看的！";
	nQ[6].A3="C、在喜歡的人面前還是保持風度吧，下次再給我碰到你就知道難看了！";
	nQ[6].A4="D、冷冷地說：你的服務態度一向都這麼好嗎？";
	nQ[6].isq=1;
	nQ[6].next[0]=7;
	nQ[6].next[1]=7;
	nQ[6].next[2]=8;
	nQ[6].next[3]=8;
	
	
	nQ[7].Q="7、 為了看火星，你買了一臺高倍數的望遠鏡，轉著轉著，不小心轉到別人家去了，你會希望照到的地方是：";
	nQ[7].A1="A、這還用說，當然是有美女洗澡的浴室。";
	nQ[7].A2="B、臥室！看看有沒有激情畫面可以欣賞。";
	nQ[7].A3="C、我錯了我錯了！快點轉開才對！ ";
	nQ[7].A4="D、欣賞欣賞別人家也不錯，轉到哪就看到哪羅！ ";
	nQ[7].isq=1;
	nQ[7].next[0]=8;
	nQ[7].next[1]=8;
	nQ[7].next[2]=14;
	nQ[7].next[3]=12;
	
	
	nQ[8].Q="8、 去Shopping時，因為人太多了，找錢時小姐不僅多找了你錢，甚至連你買的東西也順便「升級」了，這時你會：";
	nQ[8].A1="A、「升級」的東西不見得符合我的需要，東西當然還是要換回來比較好。 ";
	nQ[8].A2="B、錢找錯了是她的不對，進我口袋的東西哪還有還回去的道理，叫她自作自受吧。 ";
	nQ[8].A3="C、幹嘛和自己過不去啊，能拿就拿，就當作今天是lucky day，通通收下來吧！ ";
	nQ[8].A4="D、怎麼可以為難人家呢？把東西還回去，順便跟她要電話好了！ ";
	nQ[8].isq=1;
	nQ[8].next[0]=13;
	nQ[8].next[1]=10;
	nQ[8].next[2]=9;
	nQ[8].next[3]=11;
	
	nQ[9].Q="A 級魔鬼開膛手傑克\n\t你心狠手辣，不高興絕對不會藏在心理，有不爽一定要發泄出來，你的座右銘是「有仇必報」，雖然有時候也會耍點小陰險，但大多時候的你總是可以讓人感覺到你火辣辣的脾氣。";
	nQ[9].isq=0;
	nQ[10].Q="B 級魔鬼撒旦\n\t沒錯！你就是貨真價實的壞胚子！或許你也曾經相信過人性本善，但是看多了人性醜陋的那一面後，你除了轉而相信人性本惡之外，甚至還常常慫恿別人做壞事，嘖嘖嘖……果然很有當惡魔的潛力啊！";
	nQ[10].isq=0;
	nQ[11].Q="C 級魔鬼綠魔女\n\t你的個性就是那麼古靈精怪，如果這個特質可以好好發揮的話，會許你也能成為天使也不一定；不過你偏偏要步入歧途，所以老是愛用自己的小聰明作弄別人，小心啊！聰明也有被聰明誤的一天啊！";
	nQ[11].isq=0;
	nQ[12].Q="D 級魔鬼濕婆\n\t你這個人乍看之下似乎無毒無害，平常看起來也一付道貌岸然的模樣，但是只要踩到你的地雷、刺中你的要害，那麼你很可能就立刻翻臉不認人，馬上抓狂起來，情緒的落差太大，讓人怕怕啊！";
	nQ[12].isq=0;
	nQ[13].Q="E 級魔鬼阿�堸涂n\t其實說起來，你並不能算是「惡魔」，大概只稱得上是「有點壞心眼」而已。因為和真正的惡魔比起來，有時候你實在太過善良，但和天使比起來你又不夠純潔，不上不下的你，很可能在別人的慫恿之下做壞事喔！";
	nQ[13].isq=0;
	nQ[14].Q="F 級魔鬼阿修羅\n\t這麼說吧！其實你集善良和邪惡於一身，說得貼切一點，就像是「重道義的大哥」就對了！你並不會隨意為非作歹，大多數時候你只是為朋友兄弟出頭而已，所以這樣的個性倒是很受到大家的歡迎哩！";
	nQ[14].isq=0;
	
	
	for(i=9;i<15;i++)
	{
		nQ[i].isq=0;
	}

}

int chans(char);	//宣告判斷選擇

 
/*************主程式******************/ 
int main(void)
{
	reset();
	int i;
	int n=1;
	char cha;
	int tmp=0;
	clock_t start,end;
	end=start=clock();
	do{
		system("cls");
		printf("剩餘時間：%d 秒",10-((int)end-start)/CLK_TCK);
		printf("\n\n%s\n",nQ[n].Q);
		if(nQ[n].isq==1)
		{
			printf("\t%s\n",nQ[n].A1);
			printf("\t%s\n",nQ[n].A2);
			printf("\t%s\n",nQ[n].A3);
			printf("\t%s\n",nQ[n].A4);
		
			printf("請選擇：");
			
			cha=kbhit();
			if(cha==0)
			{
				end=clock();
				if((end-start)/CLK_TCK>=10)
				{
					printf("\n超過十秒,即將結束!!\n");
					exit(0);
				}
				continue;
			}
			else
				start=clock();
			n=nQ[n].next[chans(cha)-1];
		}
	}while(nQ[n].isq==1);
		system("cls");
		printf("\n\n%s\n\n\n",nQ[n].Q);
		system("pause");
}


/*************判斷選擇*********************/
int chans(char input)
{
	switch(input)
	{
		case 'A':
		case 'a':
		case '1':
			return 1;
			break;
		case 'B':
		case 'b':
		case '2':
			return 2;
			break;
		case 'C':
		case 'c':
		case '3':
			return 3;
			break;
		case 'D':
		case 'd':
		case '4':
			return 4;
			break;
		default:
			printf("選擇錯誤,請重新選擇:");
			char cha;
			cha=getche();
			return chans(cha);
	}
}
