#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

void TasKagitMakas() {
  int n;

  char kullanici, bilgisayar, sonuc;

  srand(time(NULL));

  n = rand() % 100;

  if (n < 33)
    bilgisayar = 't';
  else if (n > 33 && n < 66)
    bilgisayar = 'k';
  else
    bilgisayar = 'm';

  printf("TAS icin t | KAGIT icin k | MAKAS icin m yaziniz: ");

  scanf(" %c", &kullanici);
  getchar();

  if (kullanici == bilgisayar)
    sonuc = -1;

  else if (kullanici == 't' && bilgisayar == 'k')
    sonuc = 0;

  else if (kullanici == 'k' && bilgisayar == 't')
    sonuc = 1;

  else if (kullanici == 't' && bilgisayar == 'm')
    sonuc = 1;

  else if (kullanici == 'm' && bilgisayar == 't')
    sonuc = 0;

  else if (kullanici == 'k' && bilgisayar == 'm')
    sonuc = 0;

  else if (kullanici == 'm' && bilgisayar == 'k')
    sonuc = 1;
  printf("\nSecimin: %c ve Karsi Tarafin Secimi: %c\n", kullanici, bilgisayar);
  if (sonuc == -1) {
    printf("\nBERABERE!\n");
  } else if (sonuc == 1) {
    printf("\nKAZANDIN!\n");
  } else {
    printf("\nKAYBETTIN!\n");
  }
}
int SayiTahmin(int *duzey, int *h, int *s){
    if((*h) == 0){
        printf("Hakkiniz kalmadigi icin maalesef oyun bitti :(");
        return 0;
    }

    int tahmin;

    printf("Lutfen 1 ile 20 arasinda bir sayi giriniz: ");
    scanf("%d", &tahmin);

    if((*s) == tahmin){
        printf("Tebrikler, dogru bildiniz! Eglence puanınız ek olarak 1P arttı!");
        duzey[8] += 1;
        return 1;
    }
    else{
        (*h)--;
        printf("Bilemediniz! Lutfen tekrar deneyiniz...\nKalan Hak Sayisi: %d\n\n", (*h));
        SayiTahmin(duzey, h, s);
    }

}
int Uyumak(int *duzey, int *b) {
    if ((*b) == 3) {
        char cikti[5][75] = {
            "Gunaydin! Yeni bir gun basliyor.",
            "Uykudan sonra kendimi taze hissediyorum.",
            "Enerjik bir sekilde gune merhaba!",
            "Uyku benim icin bir mucize, simdi daha enerjik hissediyorum.",
            "Yataktan kalktim ve gune hazirim!"
        };

        int sayi;
        sayi = rand() % 5 + 1;
        printf("Ali:");

        for (int i = 0; i < strlen(cikti[sayi]); i++) {
            printf("%c", cikti[sayi][i]);
            usleep(50000);
        }
    } else {
        printf("                 _____|~~\\_____      _____________\n");
        printf("             _-~               \\    |    \\\n");
        printf("             _-    | )     \\    |__/   \\   \\\n");
        printf("             _-         )   |   |  |     \\  \\\n");
        printf("             _-    | )     /    |--|      |  |\n");
        printf("            __-_______________ /__/_______|  |_________\n");
        printf("           (                |----         |  |\n");
        printf("            `---------------'--\\\\      .`--'          \n");
        printf("                                         `||||\n");
        char a[12] = {
            "Uyuluyor..."
        };

        for (int i = 0; i < 12; i++) {
            printf("%c", a[i]);
            usleep(50000);
        }

        printf("\n");

        duzey[1] += 2;
        duzey[7] -= 1;
        duzey[0] -= 1;
        duzey[6] -= 1;
        *b += 1;
        return Uyumak(duzey, b);
    }
}
int Uyku(int *duzey) {
    int secim;

    int uyku = 0;
    int *up = &uyku;
    int kestirme = 2;
    int *kp = &kestirme;

    printf("Secenekler:\n1.Uyumak [+6P Uyku | -3P Tuvalet | -3P Tokluk | -3 Hijyen]\n2.Kestirmek[+2P Uyku | -1P Tuvalet | -1P Tokluk | -1 Hijyen].\n3.Kahve icmek[+3P Uyku | -1P Tuvalet | +1P Tokluk | -1 Hijyen]\nAna menuye donmek icin \"0\" tusuna basiniz.\nLutfen secenegin basindaki numarayi giriniz: ");

    scanf("%d", &secim);
    getchar();

    switch (secim) {
    case 1:
        if (duzey[1] >= 4) {
            printf("Uyku %d oldugu icin Ali su an uyuyamaz.", duzey[1]);
            return Uyku(duzey);
        } else {
            return Uyumak(duzey, up);
        }
        break;
    case 2:
        return Uyumak(duzey, kp);
        break;
    case 3:
        printf("      )  (\n");
        printf("     (   ) )\n");
        printf("      ) ( (\n");
        printf("    _______)_\n");
        printf(" .-'---------|\n");
        printf("( C|/\\/\\/\\/\\/|\n");
        printf(" '-./\\/\\/\\/\\/|\n");
        printf("   '_________'\n");
        printf("    '-------'\n\n");
        char cikti[5][75] = {
            "Bu kahve gercekten harika, icimi isitti!",
            "Kahve icmek gibi bir keyif yok.",
            "Sanirim bu kahvenin aromasi favorim oldu.",
            "Kafein aldim, enerji dolu hissediyorum!",
            "Bir fincan kahve ile gun baslamak paha bicilemez."
        };

        int sayi;
        sayi = rand() % 5 + 1;

        printf("Ali: ");
        for (int i = 0; i < strlen(cikti[sayi]); i++) {
            printf("%c", cikti[sayi][i]);
            usleep(50000);
        }

        printf("\n");

        duzey[1] += 3;
        duzey[7] -= 1;
        duzey[0] += 1;
        duzey[6] -= 1;
        if (duzey[1] > 10)
            duzey[1] = 10;
        break;
    case 0:
        break;
    default:
        printf("Yanlis secenek tusladiniz...\n");
        return Uyku(duzey);
    }
}
int Kontrol(int *duzey, char (*ihtiyac)[15]) {
    if (duzey[7]<=0){
        duzey[6] -=4;
        usleep(50000);
        printf("***Ali tuvalet degeri %d oldugu icin hijyen ihtiyaci %d degerine dustu.***\n",duzey[7],duzey[6]);
        sleep(1);
    }
    int fazla[8] = {1,2,3,4,5,6,7,8};
    int az[4] = {3,5,8,7};
    for (int i=0;i<8;i++){
        if(duzey[fazla[i]] >10)
            duzey[fazla[i]]=10;
    }
    for (int i=0;i<4;i++){
        if(duzey[fazla[i]]<0)
            duzey[fazla[i]] = 0;
    }
    for (int i = 0; i < 9; i++) {
        if (duzey[i] > 10 || duzey[i] < 0) {
            if (i == 0) {
                if (duzey[i] > 10)
                    printf("\nAli mide fesadi gecirdi :(\n\n");
                else
                    printf("\nAli acliktan yere yigildi...\n\n");
            }
            printf("%s ihtiyaci %d puan oldugu icin Ali hayatini yitirdi :(\n\n",ihtiyac[i],duzey[i]);
            usleep(50000);
            printf("   ______                        ____                 \n");
            printf("  / ____/___ _____ ___  ___     / __ \\_   _____  _____\n");
            printf(" / / __/ __ `/ __ `__ \\/ _ \\   / / / / | / / _ \\/ ___/\n");
            printf("/ /_/ / /_/ / / / / / /  __/  / /_/ /| |/ /  __/ /    \n");
            printf("\\____/\\__,_/_/ /_/ /_/\\___/   \\____/ |___/\\___/_/     \n");
            sleep(1);
            char secim;
            printf("\nTekrar Oynamak ister misiniz? Evet icin \"E\" tusuna Hayir icin \"H\" tusuna basiniz: ");
            scanf(" %c",&secim);
            switch(secim){
            case 'e':
            case 'E':
                for(int i=0;i<9;i++)
                    if (i == 0 || i == 1)
                        duzey[i] = 3;
                    else
                        duzey[i] =5;
                return 1;
            case 'h':
            case 'H':
            default:
                Son(duzey,ihtiyac);
                return 0;
            }

        }
    }
}
int Tokluk(int *duzey) {
    char secim[50];
    char secim_karakter[50];
    int adet = 0, index = 0;
    printf("\n******************************** \nTokluk seviyesi %d/10! Eger 0'dan dusuk veya 10'dan yuksekse Ali hayatini kaybeder!\n********************************\n", duzey[0]);

    printf(
        "\nSecenekler:\n1.Pizza       [+3P Tokluk | -1P Tuvalet | -1P Hijyen] \n2.Muz         [+2P Tokluk | -1P Tuvalet | -1P Hijyen]\n3.Su          [+1P Tokluk | -2P Tuvalet | -1P Hijyen]\n\nAna menuye donmek icin \"0\" tusuna basiniz.\nLutfen seceneginizi adedi ile birlikte giriniz [Orn: 2 muz]: ");
    gets(secim);

    for (int i = 0; secim[i] != '\0'; i++) {
        if (isdigit(secim[i])) {
            adet = atoi(&secim[i]);

            while (isdigit(secim[i])) {
                i++;
            }
            i--;
        } else if (secim[i] != ' ') {
            secim_karakter[index] = tolower(secim[i]);
            index++;
        }
    }
    secim_karakter[index] = '\0';


    if (isalpha(secim[0])){
            adet = 1;
        }



    if (strcmp(secim_karakter, "muz") == 0) {
        duzey[0] += (adet * 2);
        duzey[7] -= adet;
        duzey[6] -= adet;

        printf("\n");
        printf("        .-.\n");
        printf("       /  |\n");
        printf("      |  /\n");
        printf("   .\'\\|.-; _\n");
        printf("  /.-.;\\  |\\|\n");
        printf("  \'   |\'._/ `\n");
        printf("      |  \\\n");
        printf("       \\  |\n");
        printf("        \'-\'  \n\n\n");
        char cikti[5][75] = {
            "Ah, bu muz gerçekten lezzetliydi!",
            "Muz yemek enerjimi artirdi.",
            "Sanirim muz yemenin en guzel yani hafifligi.",
            "Muzun icindeki vitaminler harika!",
            "Muz, saglikli bir atistirmalik."
        };
        int sayi;
        sayi = rand() % 5 + 1;

        printf("Ali: ");
        for (int i = 0; i < strlen(cikti[sayi]); i++) {
            printf("%c", cikti[sayi][i]);
            usleep(50000);
            }
        printf("\n");
    } else if (strcmp(secim_karakter, "su") == 0) {
        duzey[0] += adet;
        duzey[7] -= (adet * 2);
        duzey[6] -= adet;

        printf("\n");
        printf(" ____________\n");
        printf("<____________>\n");
        printf("|            |\n");
        printf("|            |\n");
        printf("|            |\n");
        printf(" \\          /\n");
        printf("  \\________/\n");
        printf("      ||\n");
        printf("      ||\n");
        printf("      ||\n");
        printf("      ||\n");
        printf("   ___||___\n");
        printf("  /   ||   \\\n");
        printf("  \\________/\n\n\n");
        printf("\n\n");
        char cikti[5][75] = {
            "Ah, bu su gerçekten canlandirici!",
            "Vay be, su icmek gercekten harika bir his! Taze hissettim kendimi.",
            "Sanirim susuzlugumu giderdim.",
            "Ilginc, bu suyun icinde hafif bir tat var. Yerel kaynaktan mi geldi acaba?",
            "Ah, bu su gercekten ihtiyacim olan seydi."
        };

        int sayi;
        sayi = rand() % 5 + 1;

        printf("Ali: ");
        for (int i = 0; i < strlen(cikti[sayi]); i++) {
            printf("%c", cikti[sayi][i]);
            usleep(50000);
            }
        printf("\n");
    } else if (strcmp(secim_karakter, "pizza") == 0) {
        duzey[0] += (adet * 3);
        duzey[7] -= adet;
        duzey[6] -= adet;
        printf("\n");
        printf("// \"\"--.._\n");
        printf("||  (_)  _ \"-. \n");
        printf("||    _ (_)    '-.\n");
        printf("||   (_)   __..-'\n");
        printf(" \\\\__..--\"\" ");
        printf("\n\n");
        char cikti[5][75] = {
            "Ah, bu pizza gerçekten lezzetliydi!",
            "Vay be, doyana kadar yemeye devam edebilirdim.",
            "Sanirim biraz fazla yedim, ama degdi!",
            "Ilginc bir lezzet karisimi, tekrar denemeliyim.",
            "Pizza keyfi hicbir seye degisilmez!"
        };

        int sayi;
        sayi = rand() % 5 + 1;

        printf("Ali: ");
        for (int i = 0; i < strlen(cikti[sayi]); i++) {
            printf("%c", cikti[sayi][i]);
            usleep(50000);}
        printf("\n");
    }
    else if (adet == 0){}
    else {
        printf("Hatali girdiniz....Tekrar\n");
        return Tokluk(duzey);
    }
}
void Sevgi(int *duzey, int *h, int *s) {
    int secim;
    printf("Secenekler:\n1.Sevgiliyle bulusmak                 [+3P Sevgi | +1P Sosyallesme | -2P Uyku | -1P Tokluk]\n2.Kopegi gezdirmek                    [+2P Sevgi | -1P Uyku | +2P Eglence | -1P Tokluk]\n3.Aileyle telefonda gorusmek          [+1P Sevgi | +1P Eglence]\nAna menuye donmek icin \"0\" tusuna basiniz.\nLutfen secenegin basindaki numarayi giriniz: ");
    scanf("%d", &secim);
    switch (secim){
    case 0:
        break;
    case 1:
        printf("\n");
            printf("              ., _\n");
            printf("             /    `\n");
            printf("            ((|)))))\n");
            printf("            ((/ a a\n");
            printf("            )))   >)\n");
            printf("           ((((._e((\n");
            printf("          ,--/ (-.\n");
            printf("         / \\ <\\/>/|\n");
            printf("        / /)  Lo )|\n");
            printf("       / / )    / |\n");
            printf("      |   /    ( /\n");
            printf("      |  /     ;/\n");
            printf("      ||(      | \n");
            printf("     / )|/|    \\ \n");
            printf("    |/'/\\ \\_____\\\n");
            printf("         \\   |  \\\n");
            printf("          \\  |\\  \\\n");
            printf("          |  | )  )\n");
            printf("          )  )/  /\n");
            printf("         /  /   /\n");
            printf("        /   |  /\n");
            printf("       /    | /\n");
            printf("      /     ||\n");
            printf("     /      ||\n");
            printf("      '-,_  |_\\\n");
            printf("        ( '\"'-`\n");
            printf("         \\(\\_\\\n\n\n");
            char cikti[5][75] = {
                "Ceyda'yla bulusmak her zaman heyecan verici!",
                "Ceyda ile gecirdigim zaman, gunumu guzellestiriyor.",
                "Ceyda'yla birlikte olmak benim icin bir ayricalik.",
                "Ceyda ile bulusmak, gunun en ozel ani!",
                "Ceyda ile gecirdigim her an, degerli ve unutulmaz."
            };
            int sayi;
            sayi = rand() % 5 + 1;

            printf("Ali: ");
            for (int i = 0; i < strlen(cikti[sayi]); i++) {
                printf("%c", cikti[sayi][i]);
                usleep(50000);
            }
            printf("\n");
            duzey[2] += 2;
            duzey[3] += 1;
            duzey[1] -= 2;
            duzey[0] -= 1;
            char oyun;
            printf("Sevgilinle oyun oynamak ister misin[Onaylamak icin \"E\" tusuna Red icin \"H\" tusuna basiniz]:");
            scanf(" %c", &oyun);
            getchar();
            switch(oyun){
            case 'e':
            case 'E':
                for(int flag =1;flag==1;){
                int oyun_sec;
                printf("\n1.Tas kagit makas\n2.Sayi tahmin etmece\nLutfen oynamak istediginiz oyunun numarasini giriniz:");
                scanf("%d", &oyun_sec);
                switch(oyun_sec){
                    case 1:
                        TasKagitMakas();
                        flag =0;
                        break;
                    case 2:
                        SayiTahmin(duzey, h, s);
                        flag =0;
                        break;
                    default:
                        flag =1;
                        }}
                break;
            case 'h':
            case 'H':
                break;
            }
    break;
    case 2:
            printf("\n");
            printf("     |\\_/|\n");
            printf("     | @ @   Woof!\n");
            printf("     |   <>              _\n");
            printf("     |  _/\\------____ ((| |))\n");
            printf("     |               `--' |   \n");
            printf(" ____|_       ___|   |___.'\n");
            printf("/_/_____/____/_______|\n\n");
            char sonuc3[5][75] = {
                "Kopek ile yurumek harikaydi, taze hava cok iyi geldi!",
                "Kopegimle dolasmak gunumu guzellestirdi.",
                "Dogayla ic ice olmak, kopegimle birlikte gezinmek guzel bir deneyimdi.",
                "Kopegimle yaptigimiz yuruyus beni dinlendirdi.",
                "Kopegimle gecirdigim vakit, gunumu daha ozel kildi."
            };
            int sayi3;
            sayi3 = rand() % 5 + 1;

            printf("Ali: ");
            for (int i = 0; i < strlen(sonuc3[sayi3]); i++) {
                printf("%c", sonuc3[sayi3][i]);
                usleep(50000);
            }
            printf("\n");
            duzey[2] += 2;
            duzey[1] -= 1;
            duzey[8] += 2;
            duzey[0] -= 1;
    break;
    case 3:
            printf("\n\n   _______________\n");
            printf("   /               \\\n");
            printf("  |   .---------.   |@\n");
            printf("  '---' .-----. '---'@\n");
            printf("    .' /6 5_4 3\\ '.  @\n");
            printf("    | |7 /...\\ 2| |  @\n");
            printf("    | |8 \\___/ 1| |  @\n");
            printf("    |  \\_9_0_)\\/  |  @@\n");
            printf(" /==|_____________|@@@@\n");
            printf(" H-------------------@@\n");
            printf(" H   )  ||   ||  (   @@\n");
            printf(" H  /   ||   ||   \\   @\n");
            printf(" H |----''---''----|\n");
            printf("=/ |_______________|\n\n");
            char cikti1[5][75] = {
                "Telefon gorusmesiyle ailemle baglanti kurmak harikaydi!",
                "Ailemle konusmak gunumu aydinlatti.",
                "Ailemle yapilan telefon gorusmesi beni mutlu etti.",
                "Uzakta olsak da ailemle iletisimde olmak cok degerli.",
                "Telefon gorusmesiyle ailemle aramizdaki bag guclendi."};
            int sayi4;
            sayi4 = rand() % 5 + 1;

            printf("Ali: ");
            for (int i = 0; i < strlen(cikti1[sayi4]); i++) {
                printf("%c", cikti1[sayi4][i]);
                usleep(50000);
            }
            printf("\n");
            duzey[2] += 1;
            duzey[8] += 1;
    break;
    default:
            printf("Yanlis girdiniz. Lutfen tekrar deneyin...");
            Sevgi(duzey, s, h);
}}
void Sosyallesme(int *duzey) {
    int secim;
    printf("Secenkler:\n1.Arkadaslarla takilmak                 [+3P Sosyallesme | -2P Hijyen | -2P Tokluk | -2P Tuvalet]\n2.Hali Saha                             [+2P Sosyallesme | -1P Hijyen | -2P Tokluk | -1P Tuvalet | +2P Eglence]\n3.Topluluk bulusmalari                  [+1P Sosyallesme | -1P Hijyen | +2P Tokluk | +1P Eglence]\nAna menuye donmek icin \"0\" tusuna basiniz.\nLutfen secenegin basindaki numarayi giriniz: ");
    scanf("%d", &secim);

    switch(secim){
        case 0:
            break;
        case 1:
            duzey[3] += 3;
            duzey[6] -= 2;
            duzey[0] -= 2;
            duzey[7] -= 2;
            int sayi;
            sayi = rand() % 5 + 1;
            if (sayi ==1){
                printf("\n");
                printf("  ___   _      ___   _      ___   _      ___   _      ___   _\n");
                printf(" [(_)] |=|    [(_)] |=|    [(_)] |=|    [(_)] |=|    [(_)] |=|\n");
                printf("  '-`  |_|     '-`  |_|     '-`  |_|     '-`  |_|     '-`  |_|\n");
                printf(" /mmm/  /     /mmm/  /     /mmm/  /     /mmm/  /     /mmm/  /\n");
                printf("       |____________|____________|____________|____________|\n");
                printf("                             |            |            |\n");
                printf("                         ___  \\_      ___  \\_      ___  \\_\n");
                printf("                        [(_)] |=|    [(_)] |=|    [(_)] |=|\n");
                printf("                         '-`  |_|     '-`  |_|     '-`  |_|\n");
                printf("                        /mmm/        /mmm/        /mmm/\n\n");
                printf("\nAli: ");
                char cikti[50]="Arkadaslarimla cs oynamak eglenceliydi. Son headshot vurusum efsaneviydi.";
                for (int i = 0; i < strlen(cikti); i++) {
                            printf("%c", cikti[i]);
                            usleep(50000);
                            }
                printf("\n");

            }
            if(sayi == 2){
                printf("\n\n                                                       .::.\n");
                printf("                                            _()_       _::_\n");
                printf("                                  _O      _/____\\_   _/____\\_\n");
                printf("           _  _  _     ^^__      / //\\    \\      /   \\      /\n");
                printf("          | || || |   /  - \\_   {     }    \\____/     \\____/\n");
                printf("          |_______| <|    __<    \\___/     (____)     (____)\n");
                printf("    _     \\__ ___ / <|    \\      (___)      |  |       |  |\n");
                printf("   (_)     |___|_|  <|     \\      |_|       |__|       |__|\n");
                printf("  (___)    |_|___|  <|______\\    /   \\     /    \\     /    \\\n");
                printf("  _|_|_    |___|_|   _|____|_   (_____)   (______)   (______)\n");
                printf(" (_____)  (_______) (________) (_______) (________) (________)\n");
                printf(" /____\\  /_______\\ /________\\ /_______\\ /________\\ /________\\\n\n");
                printf("\nAli: ");
                char cikti[50]="Satrancda bu kadar kotu oldugumu bilmiyordum.";
                for (int i = 0; i < strlen(cikti); i++) {
                            printf("%c", cikti[i]);
                            usleep(50000);
                            }
                printf("\n");

            }
            if(sayi == 3){
                printf("              __________\n");
                printf("            ./)      o  (\\.\n");
                printf("          ./     o         \\.\n");
                printf("        ./             o     \\.\n");
                printf("      ./)   o                 (\\.\n");
                printf("    ./                           \\.\n");
                printf("  ./             O           o     \\.\n");
                printf("./)_________________________________(\\.\n");
                printf("(_____________________________________)\n");
                printf("|XX|===============================|XX|\n");
                printf(" \\/                                 \\/\n\n");
                printf("\nAli: ");
                char cikti[75]="Hesabina oynasak daha eglenceli olurdu aslinda ama neyse..";
                for (int i = 0; i < strlen(cikti); i++) {
                            printf("%c", cikti[i]);
                            usleep(50000);
                            }
                printf("\n");
            }
            if(sayi == 4){
                printf("                                          $\"   *.      *Bike*\n");
                printf("              d$$$$$$$P\"                  $    J\n");
                printf("                  ^$.                     4r  \"\n");
                printf("                  d\"b                    .db\n");
                printf("                 P   $                  e\" $\n");
                printf("        ..ec.. .\"     *.              zP   $.zec..\n");
                printf("    .^        3*b.     *.           .P\" .@\"4F      \"4\n");
                printf("  .\"         d\"  ^b.    *c        .$\"  d\"   $         %\n");
                printf(" /          P      $.    \"c      d\"   @     3r         3\n");
                printf("4        .eE........$r===e$$$$eeP    J       *..        b\n");
                printf("$       $$$$$       $   4$$$$$$$     F       d$$$.      4\n");
                printf("$       $$$$$       $   4$$$$$$$     L       *$$$\"      4\n");
                printf("4         \"      \"\"3P ===$$$$$$\"     3                  P\n");
                printf(" *                 $       \"\"\"        b                J\n");
                printf("  \".             .P                    %.             @\n");
                printf("    %.         z*\"                      ^%.        .r\"\n");
                printf("       \"*==*\"                             ^\"*==*\"\n");

                printf("\nAli: ");
                char cikti[50]="Cok yoruldum ama asiri keyif aldim.";
                for (int i = 0; i < strlen(cikti); i++) {
                            printf("%c", cikti[i]);
                            usleep(50000);
                            }
                printf("\n");

            }
            if(sayi == 5){
                printf("\n\n          _____\n");
                printf("         |A .  | _____\n");
                printf("         | /\\ \\ ||A ^  | _____\n");
                printf("         |(_._)|| / \\ ||A _  | _____\n");
                printf("         |  |  || \\ / || ( ) ||A_ _ |\n");
                printf("         |____V||  .  ||(_'_)||( v )|\n");
                printf("                |____V||  |  || \\ / |\n");
                printf("                       |____V||  .  |\n");
                printf("                              |____V|\n\n");
                printf("\nAli: ");
                char cikti[100]="Oyunu eksi puan ile bitirmeseydim iyiydi. Ahmet'in oldugu oyunda kazanma ihtimalimde yoktu zaten.";
                for (int i = 0; i < strlen(cikti); i++) {
                            printf("%c", cikti[i]);
                            usleep(50000);
                            }
                printf("\n");
            }
            break;
        case 2:
            duzey[3] += 2;
            duzey[6] -= 1;
            duzey[0] -= 2;
            duzey[7] -= 1;
            duzey[8] += 2;
            printf("                                                                 ,/)\n");
            printf("                                                                 |_|\n");
            printf("           _          _          _          _          _         ].[\n");
            printf("          |.|        |.|        |.|        |.|        |.|      /~`-'~\\\n");
            printf("          ]^[        ]^[        ]^[        ]^[        ]^[     (<|%  |>)\n");
            printf("        /~`-'~\\    /~`-'~\\    /~`-'~\\    /~`-'~\\    /~`-'~\\    \\|___|/\n");
            printf("       {<|%  |>}  {<|%  |>}  {<|%  |>}  {<|%  |>}  {<|%  |>}   {/   \\\n");
            printf("        \\|___|/    \\|___|/    \\|___|/    \\|___|/    \\|___|/    /__|__\\\n");
            printf("       /\\    \\      /   \\      /   \\      /   \\      /   \\     | / \\ |\n");
            printf("       |/>/|__\\    /__|__\\    /__|__\\    /__|__\\    /__|__\\    |/   \\\n");
            printf("      _|)   \\ |    | / \\ |    | / \\ |    | / \\ |    | / \\ |    {}   {}\n");
            printf("     (_,|    \\)    (/   \\)    (/   \\)    (/   \\)    (/   \\)    |)   (|\n");
            printf("     / \\     (|_  _|)   (|_  _|)   (|_  _|)   (|_  _|)   (|_  _||   ||_\n");
            printf("  .,.\\_/,...,|,_)(_,|,.,|,_)(_,|,.,|,_)(_,|,.,|,_)(_,|,.,|,_)(_,|.,.|,_).,.\n");
            printf("\nAli: ");
            char cikti[5][100] = {
                "Hali sahada oynamak inanilmazdi, enerjim tavan yapti!",
                "Zorlu bir maccti, ama kazanmak harika hissettirdi.",
                "Futbol oynamak gercekten adrenalini artiriyor.",
                "Hali saha keyifliydi, bir sonraki maca hazirim!",
                "Ter dokmek ve futbol oynamak gunumu şahane kildi."
            };
            int sayi1;
            sayi1 = rand() % 5 + 1;
            for (int i = 0; i < strlen(cikti[sayi1]); i++) {
                        printf("%c", cikti[sayi1][i]);
                        usleep(50000);
                        }
            printf("\n");

            break;
        case 3:
            duzey[3] += 1;
            duzey[6] -= 1;
            duzey[0] += 2;
            duzey[8] += 1;

            printf("\n\n      ////\\\\\\\\\n");
            printf("      |      |\n");
            printf("     @  O  O  @\n");
            printf("      |  ~   |         \\__\n");
            printf("       \\ -- /          |\\ |\n");
            printf("     ___|  |___        | \\|\n");
            printf("    /          \\      /|__|\n");
            printf("   /            \\    / /\n");
            printf("  /  /|      |\\  \\  / /\n");
            printf(" /  / |      | \\  \\/ /\n");
            printf("<  <  |      |  \\   /\n");
            printf(" \\  \\ |      |   \\_/\n\n");
            char sonuc[5][100]={
                "Topluluk bulusmasiydi ama biraz sikildim, bir sonraki etkinlik daha heyecanli olmali.",
                "Bulusma guzeldi ama biraz monotondu, biraz degisiklik iyi olurdu.",
                "Topluluk etkinligi biraz sikiciydi, biraz daha enerji beklerdim.",
                "Toplanti biraz uzundu, daha fazla etkilesim olmaliydi.",
                "Etkinlik tamam da, biraz daha heyecan katabilir miyiz acaba?"
            };
            int sayi2;
            sayi2 = rand() % 5 + 1;
            printf("Ali:");
            for (int i = 0; i < strlen(sonuc[sayi2]); i++) {
                        printf("%c", sonuc[sayi2][i]);
                        usleep(50000);
                        }
            printf("\n");
        default:
            printf("Hatali girdiniz. Tekrar deneyin...\n");
            Sosyallesme(duzey);

    }
}
void Saglik(int *duzey){
    printf("\n1.Hastaneye Gitmek      [+3P Saglik |-1P Uyku |-2P Hijyen]\n2.Spor Yapmak           [+2P Saglik |-2P Uyku |+1P Sosyallesme |-1P Tokluk]\n3.Zihni Bosaltmak       [+1P Saglik |-1P Uyku]\nAna menuye donmek icin \"0\" tusuna basiniz.\nLutfen seceneginizi Tuslayiniz:");
    int secim;
    scanf("%d",&secim);
    switch (secim){
case 1:
    duzey[4] +=3;
    duzey[1] -=1;
    duzey[6] -=2;
    printf("    \\\\\\\\ \n");
    printf("   c  oo\n");
    printf("    | .U\n");
    printf("   __=__                        ,,,   \n");
    printf("  |.  __|___                    oo ;\n");
    printf("  ||_/  /  /                    U= _  0\n");
    printf("  \\_/__/__E   o                 /. .| |\n");
    printf("   (___ ||    |~~~~~~~~~~~~~~~~'----'~|\n");
    printf("   I---|||    |-----------------------|\n");
    printf("   I   |||    |       c(__)           |\n");
    printf("   ^   '--''  ^                       ^\n");
    char cikti[5][100] = {
        "Doktor kontrolu harikaydi, sagligim yerinde!",
        "Doktordan temiz fatura aldim, saglikli oldugumu ogrenmek harika bir duygu.",
        "Sonuclar temiz cikti, sagligimi dusundugumden daha iyi oldugunu bilmek mutluluk verici.",
        "Doktorumdan olumlu bir saglik raporu almak moralimi yukseltti.",
        "Doktordan cikarken icim rahatladi, sagligimi duzenli kontrol etmek onemli."
    };
    int sayi;
    sayi = rand() % 5 + 1;
    printf("Ali: ");
    for (int i = 0; i < strlen(cikti[sayi]); i++) {
        printf("%c", cikti[sayi][i]);
        usleep(50000);
    }
    printf("\n");
    break;
case 2:
    duzey[4] +=2;
    duzey[1] -=2;
    duzey[0] -=1;
    duzey[3] +=1;
    int karisik;
    karisik =rand() % 4 + 1;
    switch(karisik){
    case 1:
        printf("\n      .'*.*'.==.            .==.'*.*'.\n");
        printf("      '*/X@*'  (            )  '*@X\\*'\n");
        printf("       //X@    '.          .'    @X\\\\\n");
        printf("       \"X@      \\          /      @X\"\n");
        printf("  ____xX@        '        '        @Xx____\n");
        printf(" (            ____)      (____            )\n");
        printf(" '....------._____|      |_____.------....'\n");
        printf(" .'__||_________||___      ___||_________||__'.\n");
        printf(" ''------------------'    '------------------'`\n");
        char cikti1[50]="Bursa da en sevdigim spor buz pateni.";
        printf("\nAli:");
        for (int i = 0; i < strlen(cikti1); i++) {
                    printf("%c", cikti1[i]);
                    usleep(50000);}
        printf("\n");
        break;
    case 2:
        printf("\n          |\\\n");
        printf("           \\\\\n");
        printf("      .-\"\"\"-||\n");
        printf("     / _\\__ ||\n");
        printf("     |/____`||\n");
        printf("     ((__,__)|\n");
        printf("      |  __.'/\n");
        printf("      '.(_).' \n");
        printf("     .--' '--.\n");
        printf("   /`         `\\\n");
        printf("  /  \\_._|_._/  \\\n");
        printf(" /  /|       |\\  \\\n");
        printf("/ .' |  -:-  | '. \\\n");
        printf("\\ \\  |  -:-  |  / /\n");
        printf(" \\ \\ |___.___| / / \n");
        printf("  \\ \\|       |/ /\n");
        printf("  | (|'-._.-'|) |\n");
        printf("  \\_/|   |   |\\_/\n");
        printf("     \\   |   /\n");
        printf("      |  |  |\n");
        printf("      (_ | _)\n");
        printf("      |  |  |\n");
        printf("      |  |  |\n");
        printf("       \\ | /\n");
        printf(" jgs_.-'-|-'-._\n");
        printf(" .-'    / \\    '-.\n");
        printf("  )_   /   \\   _(\n");
        printf("    './     \\.'\n");
        printf("\nAli:");
        char cikti2[70]="Kapali havuzda yuzmek acik denizde yuzmek kadar eglenceli degil ama yine de guzeldi.";
        for (int i = 0; i < strlen(cikti2); i++) {
                    printf("%c", cikti2[i]);
                    usleep(50000);}
        printf("\n");
        break;
    case 3:
    case 4:
        printf("\n                  \\  |  /         ___________\n");
        printf("   ____________  \\ \\_# /         |  ___      |\n");
        printf("  |    GYM     |  \\  #/          | |   |     |\n");
        printf("  | |   |   |  |   \\\\#           | |`v'|     |\n");
        printf("  |            |    \\#  //       |  --- ___  |\n");
        printf("  | |   |   |  |     #_//        |     |   | |\n");
        printf("  |            |  \\\\ #_/_______  |     |   | |\n");
        printf("  | |   |   |  |   \\\\# /_____/ \\ |      ---  |\n");
        printf("  |            |    \\# |+ ++|  | |  |~~~~~~| |\n");
        printf("  |            |    \\# |+ ++|  | |  |~~~~~~| |\n");
        printf("~~|    (~~~~~) |~~~~~#~| H  |_ |~|  | |||| | |\n");
        printf("  |    ( ||| ) |     # ~~~~~~    |  | |||| | |\n");
        printf("  ~~~~~~~~~~~~~________/  /_____ |  | |||| | |\n");
        printf("                                 ~~~~~~~~~~~~~\n");
        printf("\nAli:");
        char cikti3[50]="Kaslarimin gelisimini hissedebiliyorum. Daha fazla calismaliyim.";
        for (int i = 0; i < strlen(cikti3); i++) {
                    printf("%c", cikti3[i]);
                    usleep(50000);}
        printf("\n");
        break;
    }
    break;
case 3:
    printf("\n       .--.                   .---.\n");
    printf("   .---|__|           .-.     |~~~|\n");
    printf(".--|===|--|_          |_|     |~~~|--.\n");
    printf("|  |===|  |'\\     .---!~|  .--|   |--|\n");
    printf("|%%|   |  |.'\\    |===| |--|%%|   |  |\n");
    printf("|%%|   |  |\\.'\\   |   | |__|  |   |  |\n");
    printf("|  |   |  | \\  \\  |===| |==|  |   |  |\n");
    printf("|  |   |__|  \\.'\\ |   |_|__|  |~~~|__|\n");
    printf("|  |===|--|   \\.'\\|===|~|--|%%|~~~|--|\n");
    printf("^--^---'--^    `-'`---^-^--^--^---'--'\n\n");
    char cikti2[5][100] = {
        "Kitap okumak harikaydı, zihnimi tamamen boşalttım!",
        "Her satırda kayboldum, şu an huzurlu bir zihinle doluyum.",
        "Kitapların dünyasına dalıp gerçek dünyayı unutmak nefis bir duygu.",
        "Okuduğum kitap sayesinde tüm stresimden kurtuldum.",
        "Kitaplarla dolu bir saat geçirdim ve şimdi zihinsel olarak taze hissediyorum."
    };
    int sayi2;
    sayi2 = rand() % 5 + 1;
    printf("Ali: ");
    for (int i = 0; i < strlen(cikti2[sayi2]); i++) {
        printf("%c", cikti2[sayi2][i]);
        usleep(50000);
    }
    printf("\n");
    break;
case 0:
    break;
default:
    printf("\n Yanlis giris yaptiniz.\n");
    return Saglik(duzey);
}
}
void Egitim(int *duzey) {
    printf("\n1.Okula Gitmek             [+2P Egitim |+2P Sosyallesme |-2P Tokluk|-3P Uyku]\n2.Yazilim dili ogrenmek    [+3P Egitim |-1P Eglence |-1P Tokluk]\n3.Dil Calismak             [+1P Egitim |-2P Uyku]\nAna menuye donmek icin \"0\" tusuna basiniz.\nLutfen seceneginizi Tuslayiniz:");
    int secim;
    scanf("%d",&secim);
    switch (secim){
case 1:
    duzey[5] +=2;
    duzey[3] +=2;
    duzey[0] -=2;
    duzey[1] -=3;
    printf("\n                 _ _.-'`-._ _\n");
    printf("                ;.'________'.;\n");
    printf("     _________n.[____________].n_________\n");
    printf("    |\"\"_\"\"_\"\"_\"\"||==||==||==||\"\"_\"\"_\"\"_\"\"|\n");
    printf("    |\"\"\"\"\"\"\"\"\"\"\"||..||..||..||\"\"\"\"\"\"\"\"\"\"\"|\n");
    printf("    |LI LI LI LI||LI||LI||LI||LI LI LI LI|\n");
    printf("    |.. .. .. ..||..||..||..||.. .. .. ..|\n");
    printf("    |LI LI LI LI||LI||LI||LI||LI LI LI LI|\n");
    printf(" ,,;;,;;;,;;;,;;;,;;;,;;;,;;;,;;,;;;,;;;,;;,,\n");
    printf(";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
    char cikti2[50]="Siradan bir okul gunu...";
    for (int i = 0; i < strlen(cikti2); i++) {
            printf("%c", cikti2[i]);
            usleep(50000);
            }
    printf("\n");
    break;
case 2:
    duzey[5] +=3;
    duzey[8] -=1;
    duzey[0] -=1;
    printf("\n              _\n");
    printf("             | |\n");
    printf("             | |===( )   //////\n");
    printf("             |_|   |||  | o o|\n");
    printf("                    ||| ( c  )                  ____\n");
    printf("                     ||||||                   ||   \\_\n");
    printf("                      |||||                   ||     |\n");
    printf("                      |||||                ...||__/|-\"\n");
    printf("                        |||             __|________|__\n");
    printf("                        |||             |______________|\n");
    printf("                        |||             || ||      || ||\n");
    printf("                        |||             || ||      || ||\n");
    printf("------------------------|||-------------||-||------||-||-------\n");
    printf("                        |__>            || ||      || ||\n\n");
    char cikti1[5][100] = {
        "Yine bir hata daha! Bu ne karmasa, yeter artik!",
        "Hata veren kod parcacigina bakmak can sikici olmaya basladi.",
        "Baska bir hata... Gercekten bunaldim, duzeltmekten yoruldum.",
        "Kodumu duzeltmeye calistikca daha fazla hata cikiyor gibi hissediyorum.",
        "Bu hatalar beni deli ediyor, programim hicbir zaman hatasiz calismiyor."
    };
    int sayi1;
    sayi1 = rand() % 5 + 1;
    printf("Ali: ");
    for (int i = 0; i < strlen(cikti1[sayi1]); i++) {
        printf("%c", cikti1[sayi1][i]);
        usleep(50000);
        }
    printf("\n");
    break;
case 3:
    duzey[5] +=1;
    duzey[1] -=2;
    printf("\n      __...--~~~~~-._   _.-~~~~~--...__\n");
    printf("    //               `V'               \\\\ \n");
    printf("   //                 |                 \\\\ \n");
    printf("  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\ \n");
    printf(" //__.....----~~~~._\\ | /_.~~~~----.....__\\\\\n");
    printf("====================\\\\|//====================\n");
    printf("                    `---`\n");
    char cikti[5][100] = {
        "Yabanci dil calismak biraz zorlayiciydi, ama ne de olsa pratik yapmak onemli!",
        "Dil calismak beni biraz yordu, ama kendimi gelistirdigimi bilmek guzel.",
        "Yeni dil ogrenmek biraz zorlu olabilir, ama bu beni daha motive ediyor.",
        "Dil calistim ve gercekten yoruldum, ama ilerleme kaydetmek harika bir his!",
        "Yabanci dil calismak biraz zor olabilir, ama sonunda buna degecegini bilmek mutluluk verici."
    };
    int sayi;
    sayi = rand() % 5 + 1;
    printf("Ali: ");
    for (int i = 0; i < strlen(cikti[sayi]); i++) {
        printf("%c", cikti[sayi][i]);
        usleep(50000);
        }
    printf("\n");
    break;
case 0:
    break;
default:
    printf("\n Yanlis giris yaptiniz.\n");
    Egitim(duzey);
}
}
void Hijyen(int *duzey){
    char secim[50];
    char secim_karakter[50];
    int adet = 0, index = 0;
    printf("\nSecenekler:\n1.El Yika            [+1P Hijyen | +1P Saglik]\n2.Dus Al             [+3P Hijyen | +2P Saglik | -1P Tokluk]\n3.Disleri Fircala    [+1P Saglik | +1P Hijyen]\nAna menuye donmek icin \"0\" tusuna basiniz.\nLutfen seceneginizi adedi ile birlikte giriniz:");
    gets(secim);
    for (int i = 0; secim[i] != '\0'; i++) {
        if (isdigit(secim[i])) {
            adet = atoi(&secim[i]);

            while (isdigit(secim[i])) {
                i++;
            }
            i--;
        } else if (secim[i] != ' ') {
            secim_karakter[index] = tolower(secim[i]);
            index++;
        }
    }
    secim_karakter[index] = '\0';

    if (isalpha(secim[0])){
            adet = 1;
        }

    if (strcmp(secim_karakter, "elyika") == 0){
        duzey[6] += adet;
        duzey[4] += adet;
        printf("\n\n                        ___\n");
        printf("                      .' _ '.\n");
        printf("                     / /` `\\ \\\n");
        printf("                     | |   [__]\n");
        printf("                     | |    {{\n");
        printf("                     | |    }}\n");
        printf("                  _  | |  _ {{\n");
        printf("      ___________<_>_| |_<_>}}________\n");
        printf("          .=======^=(___)=^={{====.\n");
        printf("         / .----------------}}---. \\\n");
        printf("        / /                 {{    \\ \\\n");
        printf("       / /                  }}     \\ \\\n");
        printf("      (  '========================='  )\n");
        printf("       '-----------------------------'\n\n");
        char cikti[5][75] = {
            "Ah, ellerimi yikamak gercekten ferahlatti!",
            "Ellerimi yikamak hijyenin bir parcasi olmali.",
            "Sik sik ellerimi yikamak saglik icin onemli.",
            "Temiz eller, saglikli bir gelecektir.",
            "Ellerimi yikadim ve simdi daha iyi hissediyorum."};
        int sayi;
        sayi = rand() % 5 + 1;
        printf("Ali: ");
        for(int i = 0 ; i < strlen(cikti[sayi]) ; i++){
          printf("%c",cikti[sayi][i]);
          usleep(50000);
        }
        printf("\n");

    }
    else if(strcmp(secim_karakter, "dusal") == 0){
        duzey[6] += adet*3;
        duzey[4] += adet*2;
        duzey[0] -= adet;
        printf("\n\n          .    (      )\n");
        printf("        '   . (  (  )\n");
        printf("       ,___________.\n");
        printf("       | _________ |\n");
        printf("       ||  ,###   ||\n");
        printf("       ||  ####' %||\n");
        printf("       ||   ##`  #||\n");
        printf("       ||  :### # ||\n");
        printf("       ||  '####/ ||\n");
        printf("       ||   ##`   ||\n");
        printf("       ||  ###;   ||\n");
        printf("       ||-_-_-_-_-||\n");
        printf("       ||  '###;  ||\n");
        printf("       ||   '6#'  ||\n");
        printf("       ||    ;#'  ||\n");
        printf("       ||  ;#`#;  ||\n");
        printf("       || #!' #   ||\n");
        printf("       ||%____#___||\n");
        printf("       |___________|\n\n");
        char cikti[5][75] = {
        "Ah, dusun altinda rahatlamak harikaydi!",
        "Sicak su gercekten rahatlaticiydi, enerjim yerine geldi.",
        "Dus almak gunun en iyi ani!",
        "Temizlenmek harika bir duygu, simdi taze hissediyorum.",
        "Dus aldiktan sonra rahatlamis bir sekilde yeni güne baslamak güzel."};
        int sayi;
        sayi = rand() % 5 + 1;
        printf("Ali: ");
        for(int i = 0 ; i < strlen(cikti[sayi]) ; i++){
          printf("%c",cikti[sayi][i]);
          usleep(50000);
        }
        printf("\n");

    }
    else if(strcmp(secim_karakter, "dislerifircala") == 0){
        duzey[6] += adet;
        duzey[4] += adet;
        printf("\n\n                                          ___                        ___\n");
        printf("                                         /\\ ..\\_                  _/   /\\\n");
        printf("                                         \\/\\   _)                (_'' /\\/ \n");
        printf("                                          \\/\\  o\\                / . /\\/  \n");
        printf("                                           \\/\\_  )              (  _/\\/   \n");
        printf("                                            \\/_)(                )(_\\/    \n");
        printf("      ____                                    (__\\______________/__)    \n");
        printf("     |___|\\                                   |\\  \\            /  /|    \n");
        printf("      |    \\                                  | \\  \\          /  / |    \n");
        printf("      |     \\                                 |  \\  \\        /  /  |    \n");
        printf("      |      \\               ___              |   \\  \\      /  /   |    \n");
        printf(" ____ |       \\  ____       / _ \\ ______      |    \\  \\    /  /    |    \n");
        printf("/|_||\\|________\\/|_||\\___  / // //    \\ \\     |     \\  \\  /  /     |    \n");
        printf("_________________________\\-\\ \\_//      \\/-__ -\\__    \\__)(__/    __/------\n");
        printf("                            \\_________ / ||||   [][][][][][][][][]\n");
        printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n\n\n");
        char cikti[5][75] = {
        "Ah, dis fircalamak gercekten ferahlatti!",
        "Dislerimi fircalamak gunluk bakimimin onemli bir parcasi.",
        "Mis gibi bir nefes almak icin dislerimi temiz tutmaliyim.",
        "Dental hijyen benim icin cok onemli!",
        "Dislerimi fircaladim ve simdi kendimi daha iyi hissediyorum."};
        int sayi;
        sayi = rand() % 5 + 1;
        printf("Ali: ");
        for(int i = 0 ; i < strlen(cikti[sayi]) ; i++){
          printf("%c",cikti[sayi][i]);
          usleep(50000);
        }
        printf("\n");
    }
    else if(adet == 0){

    }
    else{
        printf("\n Yanlis giris yaptiniz.\n");
        Hijyen(duzey);
    }
}
void Tuvalet(int *duzey) {
    printf("\n\n                                                         |\n");
    printf("                                            __________   |\n");
    printf("                           _    __    _    |          |  |\n");
    printf("                          /_\\  /  \\  /_\\   |          |  |\n");
    printf("                          =|= | // | =|=   |          |  |\n");
    printf("                           !   \\__/   !    |          |  |\n");
    printf("                                 _         |          |  |\n");
    printf(" ___               ___          //'        |          |  |\n");
    printf("[___]       _   :=|   |=:   __T_||_T__     |p=        |  |\n");
    printf("|  ~|     =)_)=   |   |    [__________]    |          |  |\n");
    printf("|   |      (_(    |xXx|     \\_      _/     |          |  |\n");
    printf("|   |      )_)    \"\"\"\"\"       \\    /       |          |  |\n");
    printf("\\___|                          |  |        |          |  |\n");
    printf(" |  `========,                 |  |        |          |  |\n");
    printf("__`.        .'_________________|  |________|__________lc_|\n");
    printf("    `.    .'                  (____)                      \\\n");
    printf("    _|    |_...             .;;;;;;;;.                     \\\n");
    printf("   (________);;;;          :;;;;;;;;;;:\n");
    printf("        :::::::'            '::::::::'\n\n");
    char cikti[5][75] = {
        "Ah, rahatlamak guzeldi!",
        "Biraz zaman kendime ayirmak her zaman iyi gelir.",
        "Tuvalet molasi sonrasi enerji dolu hissediyorum.",
        "Iyi ki tuvalet yakindaydi, rahatladim!",
        "Tuvalet ihtiyacini gidermek gercekten hafifletici."
    };
    int sayi;
    sayi = rand() % 5 + 1;
    printf("Ali: ");
    for(int i = 0 ; i < strlen(cikti[sayi]) ; i++){
        printf("%c",cikti[sayi][i]);
        usleep(50000);}
    printf("\n");
    duzey[6] -=1;
    duzey[7] +=3;
    printf("Tuvalet ihtiyaci giderildi | [+3P Tuvalet | -1P Hijyen]....");
}
void Eglence(int *duzey, int *h, int *s) {
    printf("\n1.Film Izlemek       [+3P Eglence |-2P Uyku |+1P Sosyallesme]\n2.Oyun Oynamak       [+2P Eglence |-1P Uyku]\n3.Muzik Dinlemek     [+1P Eglence]\nAna menuye donmek icin \"0\" tusuna basiniz.\nLutfen seceneginizi Tuslayiniz:");
    int secim;
    scanf("%d",&secim);
    switch (secim){
case 1:
    duzey[8] +=3;
    duzey[1] -=2;
    duzey[3] +=1;
    int a;
    a = rand() % 5 + 1;
    switch(a){
        case 1:
            printf("                T\\ T\\\n");
            printf("                | \\| \\\n");
            printf("                |  |  :\n");
            printf("           _____I__I  |\n");
            printf("         .'            '.\n");
            printf("       .'                '\n");
            printf("       |   ..             '\n");
            printf("       |  /__.            |\n");
            printf("       :.' -'             |\n");
            printf("      /__.                |\n");
            printf("     /__, \\               |\n");
            printf("        |__\\        _|    |\n");
            printf("        :  '\\     .'|     |\n");
            printf("        |___|_,,,/  |     |    _..--.\n");
            printf("     ,--_-   |     /'      \\../ /  /\\\\\n");
            printf("    ,'|_ I---|    7    ,,,_/ / ,  / _\\\\\n");
            printf("  ,-- 7 \\|  / ___..,,/   /  ,  ,_/   '-----.\n");
            printf(" /   ,   \\  |/  ,____,,,__,,__/            '\\\n");
            printf(",   ,     \\__,,/                             |\n");
            printf("| '.       _..---.._                         !.\n");
            printf("! |      .' z_M__s. '.                        |\n");
            printf(".:'      | (-_ _--')  :          L            !\n");
            printf(".'.       '.  Y    _.'             \\,         :\n");
            printf(" .          '-----'                 !          .\n");
            printf(" .           /  \\                   .          .\n");
            char tepki1[100]="Bu adam ayni ben.";
            printf("\nAli: ");
            for(int i=0;i<=strlen(tepki1);i++){
                printf("%c",tepki1[i]);
                usleep(50000);
            }
            printf("\n");
        break;
        case 2:
            printf("\n                        .-\"\"\"\"\"-.\n");
            printf("                       / j      \\\n");
            printf("                      :.d;       ;\n");
            printf("                      $$P        :\n");
            printf("           .m._       $$         :\n");
            printf("          dSMMSSSss.__$$b.    __ :\n");
            printf("         :MMSMMSSSMMMSS$$$b.  $$P ;\n");
            printf("         SMMMSMMSMMMSSS$$$$     :b\n");
            printf("        dSMMMSMMMMMMSSMM$$$b.dP SSb.\n");
            printf("       dSMMMMMMMMMMSSMMPT$$=-. /TSSSS.\n");
            printf("      :SMMMSMMMMMMMSMMP  `$b_.'  MMMMSS.\n");
            printf("      SMMMMMSMMMMMMMMM \\  .'/    :SMMMSSS.\n");
            printf("     dSMSSMMMSMMMMMMMM  \\/_/; .'SSMMMMSSSm\n");
            printf("    dSMMMMSMMSMMMMMMMM    :.;'\"  SSMMMMSSMM \n");
            printf("  .MMSSSSSMSSMMMMMMMM;    :.;   MMSMMMMSMMM;\n");
            printf(" dMSSMMSSSSSSSMMMMMMM;    ;.;   MMMMMMMSMMM\n");
            printf(":MMMSSSSMMMSSP^TMMMMM     ;.;   :MMMMMMMMM;\n");
            printf("MMMSMMMMSSSSP   `MMMM     ;.;   :MMMMMMMM\n");
            printf("\"TMMMMMMMMMM      TM;    :`.:    MMMMMMMMM;\n");
            printf("   )MMMMMMM;     _/\\\\    :`.:    :MMMMMMMM\n");
            printf("  d$SS$$$MMMb.  |._\\\\\\   :`.:     MMMMMMMM;\n");
            printf("  T$$S$$$$$$$$$$m;O\\\\\\\\\"-;`.:_.-  MMMMMMM;\n");
            printf(" :$$$$$$$$$$$$$$$b_l./\\\\ ;`.:    mMMSSMMM;\n");
            printf(" :$$$$$$$$$$$$$$$$$$$. \\\\`.:.$$$$SMSSSMMM;\n");
            printf("  $$$$$$$$$$$$$$$$$$$$. \\.:$$$$SSMMMMMMM\n");
            printf("  :$$$$$$$$$$$$$$$$$$$$$.//.:$$$$$SSMMMMMMM\n");
            printf("  :$$$$$$$$$$$$$$$$$$$$$$.`.:$$.  `SSSMMMM\n");
            printf("   $$$$$$$$$$$$$$$$$$$$$$.//.:     mMM$$b\n");
            printf("   :$$$$$$$$$$$$$$$$$$$$$$.`.:  .$$MSMMMMMM\n");
            printf("    $$$$$$$$$;\"^$J \"^$$$$;.`.$$P  `SSSMMMM\n");
            printf("    :$$$$$$$$$       :$$$;.`.P'..   TMMM$$b\n");
            printf("    :$$$$$$$$$;      $$$$;.`/ c^'   d$$$$$S;\n");
            printf("    j    `SSSSS$     _/\\    :`.:    :$$$$$$\n");
            printf("   :       \"^S^'     '-'          :$$$$$$$\n");
            printf("-hrr-                          \"\"^^T$$$$P\"\n\n");
            char tepki2[100]="Tasiyici filmi kadar gereksiz aksiyon iceren bir film yok.";
            printf("\nAli: ");
            for(int i=0;i<=strlen(tepki2);i++){
                printf("%c",tepki2[i]);
                usleep(50000);
            }
            printf("\n");
        break;
        case 3:
            printf("\n                       .-.\n");
            printf("                      |_:_|\n");
            printf("                     /(_Y_)\\\n");
            printf(".                   ( \\/M\\/ )\n");
            printf(" '.               _.'-/'-\\'-._\n");
            printf("   ':           _/.--'[[[[]'--.\\_\n");
            printf("     ':        /_'  : |::\"| :  '.\\\n");
            printf("       ':     //   ./ |oUU| \\'  :\\\n");
            printf("         ':  _:'..' \\_|___|_/ :   :\n");
            printf("           ':.  .'  |_[___]_|  :.':\\\n");
            printf("            [::\\ |  :  | |  :   ; : \\\n");
            printf("             '-'   \\/'.| |.' \\  .;.' |\n");
            printf("             |\\_    \\ '-'   :       |\n");
            printf("             |  \\    \\ .:    :   |   |\n");
            printf("             |   \\    | '.   :    \\  |\n");
            printf("             /       \\   :. .;       |\n");
            printf("            /     |   |  :__/     :  \\\\\n");
            printf("           |  |   |    \\:   | \\   |   ||\n");
            printf("          /    \\  : :  |:   /  |__|   /\n");
            printf("      snd |     : : :_/_|  /'.\\  '--|_\\\n");
            printf("          /___.-/_|-'   \\  \\\n");
            printf("                         '-'\n\n");
            char tepki3[100]="Bir filmide iyiler kazansin bee.";
            printf("\nAli: ");
            for(int i=0;i<=strlen(tepki3);i++){
                printf("%c",tepki3[i]);
                usleep(50000);
            }
            printf("\n");

        break;
        case 4:
            printf("\n                             ,--.\"\"\n");
            printf("                      __,----( o ))\n");
            printf("                    ,'--.      , (\n");
            printf("             -\",:-(    o ),-'/  ;\n");
            printf("               ( o) `o  _,'\\ / ;(\n");
            printf("                `-;_-<\\'_\\-'/ '  )\n");
            printf("                    `.`-.__/ '   |\n");
            printf("       \\`.            `. .__,   ;\n");
            printf("        )_;--.         `\\`       |\n");
            printf("       /'(__,-:         )      ;\n");
            printf("     ;'    (_,-:     _,::     .|\n");
            printf("    ;       ( , ) _,':::'    ,;\n");
            printf("   ;         )-,;'  `:'     .::\n");
            printf("   |         `'  ;         `:::\\\n");
            printf("   :       ,'    '            `:\\\n");
            printf("   ;:    '  _,-':         .'     `-. \n");
            printf("    ';::..,'  ' ,        `   ,__    `.\n");
            printf("      `;''   / ;           _;_,-'     `.\n");
            printf("            /            _;--.          \\\n");
            printf("          ,'            / ,'  `\\.         \\\n");
            printf("         /:            (_(   ,' \\         )\n");
            printf("        /:.               \\_(  /-. .:::,;/\n");
            printf("       (::..                 `-`\\ \"\"\"'\n");
            printf("       ;::::.                    \\        __\n");
            printf("       ,::::::.            .:'    )    ,-'  )\n");
            printf("      /  `;:::::::'`__,:.:::'    /`---'   ,'\n");
            printf("     ;    `\"\"\"'   (  \\:::'     /     _,-'\n");
            printf("     ;              \\  \\:'    ,';:.,-'\n");
            printf("     (              :  )\\    (\n");
            printf("      `.             \\   \\    ;\n");
            printf("-hrr-   `-.___       : ,\\ \\  (\n");
            printf("           ,','._::::| \\ \\ \\  \\\n");
            printf("          (,(,---;;;;;  \\ \\|;;;)\n");
            printf("                      `._\\_\\ \n\n");
            char tepki4[100]="Hanim haim bunlar benim yavrularim.";
            printf("\nAli: ");
            for(int i=0;i<=strlen(tepki4);i++){
                printf("%c",tepki4[i]);
                usleep(50000);
            }
            printf("\n");
        break;
        case 5:
            printf("                   ,,,,\n");
            printf("             ,;) .';;;;',\n");
            printf(" ;;,,_,-.-.,;;'_,|I\\;;;/),,_\n");
            printf("  `';;/:|:);{ ;;;|| \\;/ /;;;\\__\n");
            printf("      L;/-';/ \\;;',/;\\/;;;.') \\\n");
            printf("      .:`''` - \\;;'.__/;;;/  . _'-._\n");
            printf("    .'/   \\     \\;;;;;;/.'_7:.  '). \\_\n");
            printf("  .''/     | '._ );}{;//.'    '-:  '.,L\n");
            printf(".'. /       \\  ( |;;;/_/         \\._./;\\   _,\n");
            printf(". /        _;:':;;;;:';-._             );\n");
            printf("/        /   \\  `'`   --.'-._         \\/\n");
            printf("       .'     '.  ,'         '-,\n");
            printf("      /    /   r--,..__       '.\\\n");
            printf("    .'    '  .'        '--._     ]\n");
            printf("    (     :.(;>        _ .' '- ;/\n");
            printf("    |      /:;(    ,_.';(   __.'\n");
            printf("     '- -'" "|;:/    (;;;;-'--'\n");
            printf("           |;/      ;;(\n");
            printf("           \\;;|\n");
            printf("            \\/\n");
            char tepki5[120]="Tobey > Andrew > Tom. Aksini iddia eden etmesin.";
            printf("\nAli: ");
            for(int i=0;i<=strlen(tepki5);i++){
                printf("%c",tepki5[i]);
                usleep(50000);
            }
            printf("\n");
        break;
    }
break;
case 2:
    duzey[8] +=2;
    duzey[1] -=1;
    for(int flag =1;flag==1;){
        char oyun_sec;
        printf("\n1.Tas kagit makas\n2.Sayi tahmin etmece\nLutfen oynamak istediginiz oyunun numarasini giriniz:");
        scanf(" %c", &oyun_sec);
        switch(oyun_sec){
            case '1':
                TasKagitMakas();
                flag =0;
                break;
            case '2':
                SayiTahmin(duzey, h, s);
                flag =0;
                break;
            default:
                flag =1;
                        }}
break;
case 3:
    duzey[8] +=1;
    printf("\n             .==============.\n");
    printf("   __________||_/########\\_||__________\n");
    printf("  |(O)____ : [FM 103.7] ooooo : ____(O)|\n");
    printf("  |  /::::\\:  _________  +|+  :/::::\\  |\n");
    printf("  |  \\;;;;/: |    |    | |+|  :\\;;;;/  |\n");
    printf("  |________:_ooooo+==ooo______:________|\n\n");
    printf("                     |\\                         __3__          |\n");
    printf("____|\\_______________|\\\\_______________|_______'__|__`___|_____|___|__________\n");
    printf("____|/___3_|________@'_\\|__|_____|_____|___|___|__|__|___|_|__@'___|___|___|__\n");
    printf("___/|____-_|____________|__|_____|____@'___|__@'_@'_@'___|_|______@'___|___|__\n");
    printf("__|_/_\\__4_|___|_______@'__|____O'_________|____________O'_|__________@'___|__\n");
    printf("___\\|/_____|___|___________|_______________|_______________|_______________|__\n");
    printf("    /         O'          \n\n");
    char muzik[5][100] = {
        "Muzik dinlemek harikaydi, tam anlamiyla eglendim!",
        "Sarkilar oyle guzeldi ki dans ettim!",
        "Muzik beni costurdu, harika bir zaman gecirdim.",
        "Playlist cok enerjikti, muzigin tadini cikardim!",
        "Sarkilarla dolu bir ani yasadim, nese dolu bir ani!"
    };
    int sayi;
    sayi = rand() % 5 + 1;

    printf("Ali: ");
    for (int i = 0; i < strlen(muzik[sayi]); i++) {
            printf("%c", muzik[sayi][i]);
            usleep(50000);
        }
    printf("\n");

break;
case 0:
break;
default:
    printf("\n Yanlis giris yaptiniz.\n");
    Eglence(duzey, s, h);
    }

}
void Son(int *duzey, char (*ihtiyac)[15]){
    printf("\n\n**********************************");
    printf("\nSON SKORLARINIZ:\n\n");
    for(int i=0; i < 9; i++){
        printf("%s: %d/10\n",  ihtiyac[i], duzey[i]);
    }
    printf("**********************************\n");
    printf("\n");
    printf("\t _____                       _ _       _       _     \n");
    printf("\t|  _  |                     | (_)     (_)     (_)    \n");
    printf("\t| | | |_   _ _ __   __ _  __| |_  __ _ _ _ __  _ ____\n");
    printf("\t| | | | | | | '_ \\ / _` |/ _` | |/ _` | | '_ \\| |_  /\n");
    printf("\t\\ \\_/ / |_| | | | | (_| | (_| | | (_| | | | | | |/ / \n");
    printf("\t \\___/ \\__, |_| |_|\\__,_|\\__,_|_|\\__, |_|_| |_|_/___|\n");
    printf("\t        __/ |                     __/ |              \n");
    printf("\t       |___/                     |___/               \n");
    usleep(500000);
    printf("\n");
    printf("\t _____     _       \n");
    printf("\t|_   _|   (_)      \n");
    printf("\t  | |  ___ _ _ __  \n");
    printf("\t  | | / __| | '_ \\ \n");
    printf("\t _| || (__| | | | |\n");
    printf("\t \\___/\\___|_|_| |_|\n");
    usleep(500000);
    printf("\n");
    printf("\t _____              _    _               _           _ \n");
    printf("\t|_   _|            | |  | |             | |         | |\n");
    printf("\t  | | ___  ___  ___| | _| | ___   _ _ __| | ___ _ __| |\n");
    printf("\t  | |/ _ \\/ __|/ _ \\ |/ / |/ / | | | '__| |/ _ \\ '__| |\n");
    printf("\t  | |  __/\\__ \\  __/   <|   <| |_| | |  | |  __/ |  |_|\n");
    printf("\t  \\_/\\___||___/\\___|_|\\_\\_|\\_\\__,_|_|  |_|\\___|_|   (_)\n");
}
int main() {
    int hak = 5;
    srand(time(NULL));
    int sayi = rand() % 20 + 1;

    int *hakp = &hak;
    int *sayip = &sayi;
    printf("\t           _      _____ _ _   _ _____ _   _ \n");
    printf("\t     /\\   | |    |_   _( ) \\ | |_   _| \\ | |\n");
    printf("\t    /  \\  | |      | | |/|  \\| | | | |  \\| |\n");
    printf("\t   / /\\ \\ | |      | |   | . ` | | | | . ` |\n");
    printf("\t  / ____ \\| |____ _| |_  | |\\  |_| |_| |\\  |\n");
    printf("\t /_/    \\_\\______|_____| |_| \\_|_____|_| \\_|\n");
    usleep(500000);
    printf("\n");
    printf("\t   _____ ______ _____  _    ___      ________ _   _ _____ \n");
    printf("\t  / ____|  ____|  __ \\| |  | \\ \\    / /  ____| \\ | |_   _|\n");
    printf("\t | (___ | |__  | |__) | |  | |\\ \\  / /| |__  |  \\| | | |  \n");
    printf("\t  \\___ \\|  __| |  _  /| |  | | \\ \\/ / |  __| | . ` | | |  \n");
    printf("\t  ____) | |____| | \\ \\| |__| |  \\  /  | |____| |\\  |_| |_ \n");
    printf("\t |_____/|______|_|  \\_\\\\____/    \\/   |______|_| \\_|_____|\n");
    usleep(500000);
    printf("\n\n");
    char metin[1000] = ("Ali, 19 yasinda sehir disinda bilgisayar muhendisligi okuyan bir universite ogrencisidir. Web alanina ilgi duymakta ve freelance website yaparak kendine ek gelir saglamaktadir. Derslerin yani sira, programlama yarismalarina ve hackathonlara katilarak bilgisayar becerilerini gelistirmeye ozen gosterirdi. Ozellikle yazilim gelistirme konusundaki tutkusu, sinif arkadaslari arasinda bilinen bir ozellik haline gelmisti. Bilgisayar laboratuvarlarinda ve kutuphanede gecirdigi saatler, onun icin adeta birer kesif yolculuguna donusmustu. Proje gruplarina katilarak ekip calismasinin keyfini cikaran Ali, hem bilgi birikimini artiriyor hem de arkadaslariyla birlikte basarili projelere imza atiyordu. Haydi Ali'nin hayatina goz atalim!");

    for (int i = 0; i < strlen(metin); i++) {
        printf("%c", metin[i]);
        usleep(50000);
    }

    char ihtiyaclar[9][15] = {
        "Tokluk",
        "Uyku",
        "Sevgi",
        "Sosyallesme",
        "Saglik",
        "Egitim",
        "Hijyen",
        "Tuvalet",
        "Eglence"
    };
    int duzey[9] = {
        3,
        3,
        5,
        5,
        5,
        5,
        5,
        5,
        5
    };
    int tus;

    int flag = 1;
    while (flag) {

        printf("\n\n\t\t      ////^\\\\\\\\  \n");
        printf("\t\t      | ^   ^ |\n");
        printf("\t\t     @ (o) (o) @\n");
        printf("\t\t      |   <   |\n");
        printf("\t\t      | \\___/ |\n");
        printf("\t\t       \\_____/\n");
        printf("\t\t     ____|  |____\n");
        printf("\t\t    /    \\__/    \\\n");
        printf("\t\t   /              \\\n");
        printf("\t\t  /\\_/|        |\\_/\\\n");
        printf("\t\t / /  |  ALI   |  \\ \\\n");
        printf("\t\t( <   |        |   > )\n");
        printf("\t\t \\ \\  |        |  / /\n");
        printf("\t\t  \\ \\ |________| / /\n");
        sleep(1.3);
        printf("\n**********************************************************\n");
        printf("\t---MENU---\t\t--Ali'nin Ihtiyac Seviyeleri--\n");

        for (int i = 0; i < 9; i++) {
            printf("%d. %s\t\t\t", i + 1, ihtiyaclar[i]);
            if (i == 1)
                printf("\t");
            printf("*%s: %d/10\n", ihtiyaclar[i], duzey[i]);
        }
        printf("\n***UYARI***\nTokluk 10'dan yuksek olursa veya Tokluk, Uyku, Sevgi, Saglik ve Hijyen ihtiyaclarindan 0'in altina duserse karakter olur.\n");
        printf("\nFonksiyon Numarasini tuslayiniz (Cikmak icin 0'a basiniz.) -> ");
        scanf("%d",&tus);
        getchar();
        switch (tus) {
        case 1:
            printf("\033c");
            Tokluk(duzey);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 2:
            printf("\033c");
            Uyku(duzey);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 3:
            printf("\033c");
            Sevgi(duzey,hakp,sayip);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 4:
            printf("\033c");
            Sosyallesme(duzey);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 5:
            printf("\033c");
            Saglik(duzey);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 6:
            printf("\033c");
            Egitim(duzey);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 7:
            printf("\033c");
            Hijyen(duzey);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 8:
            printf("\033c");
            Tuvalet(duzey);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 9:
            printf("\033c");
            Eglence(duzey,hakp,sayip);
            flag = Kontrol(duzey, ihtiyaclar);
            sleep(1.5);
            break;
        case 0:
            printf("\033c");
            Son(duzey,ihtiyaclar);
            flag=0;
            sleep(1.5);
            break;
        default:
            printf("Gecersiz secenek! Tekrar deneyin.\n");
        }
    }
    return 0;
}
