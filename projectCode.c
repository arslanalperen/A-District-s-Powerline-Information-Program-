#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include<math.h>

typedef struct indirici{
	int id;
	float x1;
	float y1;
	float x2;
	float y2;
}indirici;

typedef struct musteri{
	int id;
	int tip;
	float x1;
	float y1;
	float x2;
	float y2;
}musteri;

typedef struct hat{
	int id;
	float x1;
	float y1;
	float x2;
	float y2;
}hat;

float mesafeHesaplayici(float x1, float x2,float y1,float y2);

int main(){
	char ch[100];
	FILE *p = fopen("Realistic_system.txt","r");	
	char *checker = NULL;

	int indiriciSayisi = 0;
	int musteriSayisi = 0;
	int hatSayisi = 0;
	int tipMesken = 0;
	int tipTicari = 0;
	int tipSanayi = 0;
	
	//dinamik sekilde array olusturmak icin oncelikle sayilar tespit edilecek
	if((p=fopen("Realistic_system.txt","r")) !=NULL){
		while(!feof(p)){
			fgets(ch,100,p);
			
			checker = strstr(ch, "INDIRICI_ID");
			if(checker == ch){
				while(true){
					fgets(ch,100,p);
					checker = strstr(ch, "END");
					if(checker == ch){
						break;
					} else {
						indiriciSayisi++;
					}
				}
			}

			checker = strstr(ch, "MUSTERI_ID");
			if(checker == ch){
				while(true){
					fgets(ch,100,p);
					checker = strstr(ch, "END");
					if(checker == ch){
						break;
					} else {
						musteriSayisi++;
					}
				}
			}

			checker = strstr(ch, "HAT_ID");
			if(checker == ch){
				while(true){
					fgets(ch,100,p);
					checker = strstr(ch, "END");
					if(feof(p) || checker == ch){
						break;
					} else {
						hatSayisi++;
					}
				}
			}
		}
	} else{
		printf("Dosya Bulunamadi.");
		exit(1);
	}

	fclose(p);

	// sayilar tespit edilince, bu sayi buyukluklerinde arrayler olusturulacak
	indirici indiriciler[indiriciSayisi];
	musteri musteriler[musteriSayisi];
	hat hatlar[hatSayisi];

	char * token;
	int tabIndex = 0;
	int arrayIndex = 0;
	if((p=fopen("Realistic_system.txt","r")) !=NULL){
		while(!feof(p)){
			fgets(ch,100,p);

			checker = strstr(ch, "INDIRICI_ID");
			if(checker == ch){
				printf("indiriciler isleniyor\n");
				while(true){
					fgets(ch,100,p);
					checker = strstr(ch, "END");
					if(checker == ch){
						break;
					} else {
						token = strtok(ch, "\t");
						indiriciler[arrayIndex].id = atoi(token);
						tabIndex = 1;
					    while( token != NULL ) {
					      token = strtok(NULL, "\t");
					      switch (tabIndex)
						  {
							    case 1:
							      indiriciler[arrayIndex].x1 = strtof(token, NULL);
							      break;
							    case 2:
							      indiriciler[arrayIndex].y1 = strtof(token, NULL);
							      break;
							    case 3:
							      indiriciler[arrayIndex].x2 = strtof(token, NULL);
							      break;
							    case 4:
							      indiriciler[arrayIndex].y2 = strtof(token, NULL);
							      break;
						  }
						  tabIndex++;
					    }
						arrayIndex++;
					}
				}
				printf("indiriciler islendi\n");
			}

			arrayIndex = 0;

			checker = strstr(ch, "MUSTERI_ID");
			if(checker == ch){
				printf("musteriler isleniyor\n");
				while(true){
					fgets(ch,100,p);
					checker = strstr(ch, "END");
					if(ch == checker){
						break;
					} else {
						token = strtok(ch, "\t");
						musteriler[arrayIndex].id = atoi(token);
						tabIndex = 1;
					    while( token != NULL ) {
					      token = strtok(NULL, "\t");
					      switch (tabIndex)
						  {
							    case 1:
							      musteriler[arrayIndex].tip = atoi(token);
							      if(musteriler[arrayIndex].tip == 1)tipMesken++;
							      if(musteriler[arrayIndex].tip == 2)tipTicari++;
							      if(musteriler[arrayIndex].tip == 3)tipSanayi++;
							      break;
							    case 2:
							      musteriler[arrayIndex].x1 = strtof(token, NULL);
							      break;
							    case 3:
							      musteriler[arrayIndex].y1 = strtof(token, NULL);
							      break;
							    case 4:
							      musteriler[arrayIndex].x2 = strtof(token, NULL);
							      break;
							    case 5:
							      musteriler[arrayIndex].y2 = strtof(token, NULL);
							      break;
						  }
						  tabIndex++;
					    }
						arrayIndex++;
					}
				}
				printf("musteriler islendi\n");
			}

			arrayIndex = 0;

			checker = strstr(ch, "HAT_ID");
			if(checker == ch){
				printf("hatlar isleniyor\n");
				while(true){
					fgets(ch,100,p);
					checker = strstr(ch, "END");
					if(feof(p) || checker == ch){
						break;
					} else {
						token = strtok(ch, "\t");
						hatlar[arrayIndex].id = atoi(token);
						tabIndex = 1;
					    while( token != NULL ) {
					      token = strtok(NULL, "\t");
					      switch (tabIndex)
						  {
							    case 1:
							      hatlar[arrayIndex].x1 = strtof(token, NULL);
							      break;
							    case 2:
							      hatlar[arrayIndex].y1 = strtof(token, NULL);
							      break;
							    case 3:
							      hatlar[arrayIndex].x2 = strtof(token, NULL);
							      break;
							    case 4:
							      hatlar[arrayIndex].y2 = strtof(token, NULL);
							      break;
						  }
						  tabIndex++;
					    }
						arrayIndex++;
					}
				}
				printf("hatlar islendi\n");
			}
		}
	} else{
		printf("Dosya Bulunamadi.");
		exit(1);
	}
	
	fclose(p);
	
	FILE *p2 = fopen("Sonuclar.txt","w");
	
	//Kontrol edilmek istenilen musteri ve hat id'leri daha sonra dosyaya yazýlmak uzere aliniyor
	int k;
	int yanitMusteri=0;
	int yanitHat=0;
	printf("Kontrol etmek istediginiz musteri ID'sini giriniz: ");
	scanf("%d",&yanitMusteri);
	printf("Kontrol etmek istediginiz hat ID'sini giriniz: ");
	scanf("%d",&yanitHat);
	
	//Bu dongu eger kullaniciden alinan id mevcut ise bilgilerini yazdiriyor
	int ayirac = 0;
	for(k=0;k<musteriSayisi;k++){
		if(musteriler[k].id == yanitMusteri){
			switch(musteriler[k].tip){
				case 1:
					fprintf(p2,"Musteri Tipi: MESKEN(1)\n");
					break;
				case 2:
					fprintf(p2,"Musteri Tipi: Ticari(2)\n");
					break;
				case 3:
					fprintf(p2,"Musteri Tipi: Sanayi(3)\n");
					break;
			}
			fprintf(p2,"Istenilen musteri bilgileri: ID  X1    Y1    X2    Y2\n");
			fprintf(p2,"                              %d   %.2f  %.2f  %.2f  %.2f\n",musteriler[k].id,musteriler[k].x1,musteriler[k].y1,musteriler[k].x2,musteriler[k].y2);
			ayirac = 1;
			break;			
		}
	}
	if(ayirac==0)fprintf(p2,"Girilen id ye ait musteri bulunmamaktadir...\n");
		
	//Ýstenilen bilgiler olusturulan dosyaya yaziliyor
	fprintf(p2,"Indirici Sayisi: %d\n", indiriciSayisi);
	fprintf(p2,"Musteri Sayisi : %d\n", musteriSayisi);
	fprintf(p2,"Hat Sayisi     : %d\n", hatSayisi);
	fprintf(p2,"\n");
	fprintf(p2,"Mesken Tipi Musteri Sayisi: %d\n",tipMesken);
	fprintf(p2,"Ticari Tipi Musteri Sayisi: %d\n",tipTicari);
	fprintf(p2,"Sanayi Tipi Musteri Sayisi: %d\n",tipSanayi);
	fprintf(p2,"\n");
	fprintf(p2,"Indirici bilgileri: ID  X1    Y1    X2    Y2\n");
	//Indirici bilgileri yazdiriliyor//Birden fazla indirici durumu olmasýna karsilik for ile yazildi
	for(k=0;k<indiriciSayisi;k++){
	fprintf(p2,"                    %d  %.2f  %.2f  %.2f  %.2f\n",indiriciler[k].id,indiriciler[k].x1,indiriciler[k].y1,indiriciler[k].x2,indiriciler[k].y2);
	}
	fprintf(p2,"\n");
	
	//Hatlarin toplam uzunlugu icin islemler
	float hatToplamUzunluk=0;
	int i;
	for(i=0;i<hatSayisi;i++){
	hatToplamUzunluk += mesafeHesaplayici(hatlar[i].x1,hatlar[i].x2,hatlar[i].y1,hatlar[i].y2);
	}
	fprintf(p2,"Toplam Hat Uzunlugu: %f m'dir.",hatToplamUzunluk);
	
	fclose(p2);
	printf("Yazdirma islemi tamamlandi.");
	
	FILE *p3 = fopen("Musteri_kus_ucusu_mesafe.txt","w");
	
	float kusUcusuMesafe=0;
	int a=0;
	fprintf(p3,"ID	TIP	KUS_UCUSU_MESAFE\n");
	for(i=0;i<musteriSayisi;i++){
	kusUcusuMesafe = mesafeHesaplayici(indiriciler[a].x2,musteriler[i].x1,indiriciler[a].y2,musteriler[i].y1);
	fprintf(p3,"%d	%d	%f\n",musteriler[i].id,musteriler[i].tip,kusUcusuMesafe);
	}
	
	fclose(p3);
	printf("\nKus Ucusu mesafeler yazdirildi...");
	
	return 0;
}

float mesafeHesaplayici(float x1, float x2,float y1,float y2){
	float mesafe=0;
	float araIslem=0;
	
	araIslem = pow(x2-x1,2) + pow(y2-y1,2) ;
	
	mesafe = sqrt(araIslem);
	return mesafe;
}
