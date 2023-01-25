#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Fonksiyonlarý belirttik
void UyeEkle();
void UyeListele();
void UyeSil();
void UyeGuncelle();
void HocaEkle();
void HocaSil();
void HocaListele();
void HocaGuncelle();
void ProgramEkle();
void ProgramListele();

int main() {
	
	bool kontrol=true,uyeListeleKontrol=true,hocaKontrol=true,programKontrol=true;
	char secim;
	do{
		//                   ANA MENÜ
		printf("-----SPOR SALONU KAYIT SISTEMI-----\n");
		printf("1 - Uye Listeleme\n");
		printf("2 - Hoca Listeleme\n");
		printf("3 - Program Listeleme\n");
		printf("0 - Cikis\n");
		printf("Yukaridaki islemlerden bir tanesini seciniz:");
		scanf("%s",&secim);//seçim deðiþkenine kullanýcýdan deðer aldýðýmýz bölüm
		if(secim=='1')
		{
			//        üye listelemenin alt menüsü
			do{
			
				UyeListele();//üye listeleme fonksiyonu çalýþýr
				printf("Yukaridaki islemlerden bir tanesini seciniz:");
				scanf("%s",&secim);//seçim deðiþkenine kullanýcýdan deðer aldýðýmýz bölüm
				
				if(secim=='+')
				{	
					//database.txt dosyamýza üyelerin kayýt edildiði kýsým
					UyeEkle();
					uyeListeleKontrol=true;
				
				}else if(secim=='-'){
					//database.txt dosyamýza üyelerin silindiði kýsým
					UyeSil();
					uyeListeleKontrol=true;
				}else if(secim=='*'){
					//database.txt dosyamýza üyelerin güncellendiði kýsým
					UyeGuncelle();
					uyeListeleKontrol=true;
					
				}else if(secim=='0'){
					printf("Geri Gidiliyor...\n\n");
					uyeListeleKontrol=false;
				}
				else
				{
					printf("Lutfen Yukarida gordugunuz islemlerden bir tanesini seciniz.\n\n");
					uyeListeleKontrol=true;
				}
			}while(uyeListeleKontrol);
		}
		
		else if(secim=='2')
		{
			
			//          Hocalarýn listelendiði bölüm
			do{
			HocaListele();
			printf("\n--------------------------------------------\n");	
			printf("+ - Hoca Ekleme\n");
			printf("- - Hoca Silme\n");
			printf("* - Hoca Guncelleme\n");
			printf("0 - Cikis\n");
			printf("Yukaridaki islemlerden bir tanesini seciniz:");
			scanf("%s",&secim);//seçim deðiþkenine kullanýcýdan deðer aldýðýmýz bölüm
			if(secim=='+')
			{
				//hocadatabase.txt dosyamýza hocalarýn kayýt edildiði kýsým
				HocaEkle();
				hocaKontrol=true;
			}else if(secim=='-'){
				//hocadatabase.txt dosyamýza hocalarýn silindiði kýsým
				HocaSil();
				hocaKontrol=true;
			}else if(secim=='*'){
					//hocadatabase.txt dosyamýza hocalarýn güncellendiði kýsým
				HocaGuncelle();
				hocaKontrol=true;
			}else if(secim=='0'){
				printf("Geri gidiliyor...\n\n");
				hocaKontrol=false;
			}else{
				printf("Lütfen yukarýdaki iþlemlerden birini seçiniz.\n\n");
				hocaKontrol=true;
			}
			}while(hocaKontrol);
			
		}
		else if(secim=='3')
		{
			//        Programlarýnýn listelendiði bölüm
			do{
				ProgramListele();
				printf("\n--------------------------------------------\n");	
				printf("+ - Program Ekleme\n");
				printf("0 - Cikis\n");
				printf("Bir secim yapiniz:");
				scanf("%s",&secim);
				if(secim=='+'){
						//programdatabase.txt dosyamýza programlarýn eklendiði kýsým
					ProgramEkle();
					programKontrol=true;
				}else if(secim=='0'){
					printf("Geri gidiliyor...\n\n");
					programKontrol=false;
				}
				
			}while(programKontrol);
		
		
		
		}
		else if(secim=='0')
		{
			//                 Programý kapatan bölüm 
			printf("CIKIS YAPILIYOR....");
			kontrol=false;
			
		}
		else
		{
			//         Yanlýþ bir seçim yapýlýrsa ekranda gözükecek bölüm
		printf("Lutfen Yukarida gordugunuz islemlerden bir tanesini seciniz\n");	
		kontrol=true;
		}
		
	}while(kontrol);
	
	
	return 0;
}

void UyeEkle()
{
	char adi[20];
	char soyadi[20];
	char cinsiyetString[10];
	char cinsiyetChar;
	char tc[12],tcAra[12];
	int yas,gun,ay,yil,cnsyt,boy,hocaSec,programSec;
	float kilo;
	bool cinsiyetKontrol=true,yasKontrol=true;	
	FILE *dosya;
	dosya = fopen("uyedatabase.txt","a");//dosyamýzý ekleme modunda açýyoruz.
		if(dosya!=NULL)//dosya var mý yok mu kontrol ediyoruz
		{
			/*----------------Kullanýcan Uyelerin Bilgilerinin alýndýðý kýsým----------------*/
			printf("-------------------Uye Ekleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("Kayit etmek istediginiz uyenin Tc nosunu giriniz:");
			scanf("%s",&tc);
			printf("\nKayit etmek istediginiz uyenin adini giriniz:");
			scanf("%s",&adi);
			printf("Kayit etmek istediginiz uyenin soyadini giriniz:");
			scanf("%s",&soyadi);
		do{
			printf("Kayit etmek istediginiz uyenin cinsiyetini seciniz(E/K):");
			scanf("%s",&cinsiyetChar);
			/*--------------------Cinsiyet karakterini konrol ettiðimiz yer*/
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				strcpy(cinsiyetString, "Erkek");
				cinsiyetKontrol=false;
			}else if(cinsiyetChar == 'k'|| cinsiyetChar == 'K'){
				strcpy(cinsiyetString, "Kadin");
				cinsiyetKontrol=false;
			}else{
				printf("Lutfen E veya K harflerinden biriniz yaziniz.\n");
				cinsiyetKontrol=true;
			}	
		}while(cinsiyetKontrol);

			printf("Kayit etmek istediginiz uyenin yasini giriniz:");
			scanf("%d",&yas);
			printf("Kayit etmek istediginiz uyenin boyunu giriniz(orn:185cm):");
			scanf("%d",&boy);
			printf("Kayit etmek istediginiz uyenin kilosunu giriniz(orn:75.8):");
			scanf("%f",&kilo);
			printf("Kayit etmek istediginiz uyenin giris tarihini giriniz =>\n");
			printf("Gun: ");
			scanf("%d",&gun);
			printf("Ay: ");
			scanf("%d",&ay);
			printf("Yil: ");
			scanf("%d",&yil);
			
			ProgramListele();
			/*----------------------------------------ÝDEAL KÝLONUN HESAPLANDIÐI BÖLÜM----------------------------------------*/
			float erkek=0.9,kadin=0.8,idealKilo,fark;
			
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				idealKilo=(boy-100+yas/10)*erkek;
				fark=kilo - idealKilo;
			}else{
				float idealKilo=(boy-100+yas/10)*kadin;
				float fark=(kilo - idealKilo);
				
			}
			if(fark<0) printf("Zayifsiniz.kilo alma programini secmeniz onerilir.");
				else if(fark>=0 && fark<=10) printf("Normal Kilolusunuz.Kas kutlesi kazanma programini secmeniz onerilir ");
				else if(fark>=11 && fark<=20) printf("Fazla Kilolusunuz.Kilo verme programi veya kas kutlesi programini secmeniz onerilir");
				else if(fark>=21 && fark<=29) printf("Obezsiniz.Kilo verme programini secmeniz onerilir");
				else if(fark>=30) printf("ileri Derecede Obezsiniz.Kilo verme programini secmeniz onerilir");
				else printf("Kilo Hesaplanamadi");
			
			printf("\n\nProgram seciniz:");
			scanf("%d",&programSec);
			
			HocaListele();
			printf("Hoca seciniz:");
			scanf("%d",&hocaSec);
			
			
				
			//---------------------------Kullanýcýdan aldýðýmýz verileri 'uyedatabase.txt' dosyamýza kayýt ediyoruz.---------------------------
			fprintf(dosya,"() %s - %s - %s - %d -%s- %d - %f - Kayit Tarihi: %d / %d / %d | Ideal Kilo: %.2f | Hoca Secimi: %d | Program Secimi: %d \n",tc,adi,soyadi, yas, cinsiyetString,boy,kilo,gun,ay,yil,idealKilo,hocaSec,programSec);
			fclose(dosya);	
		}
		else{
			printf("Dosya bulunamadi...");
			fclose(dosya);
		}

}

void UyeListele(){
	FILE *dosya;
	int satir=0;
	dosya = fopen("uyedatabase.txt","r");//'uyedatabase.txt'dosyamýzý okuma modunda açýyoruz.
	char karakter;
	if(dosya != NULL)//dosyanýn olup olmadýðýný kontrol ettiðimiz bölüm
	{
		karakter = fgetc(dosya);
		while(!feof(dosya))//dosyanýn içindeki bütün karakterleri döngü ile aldýðýmýz bölüm !feof fonksiyonu dosyanýn sonuna gelinip gelinmediðini kontrol eder.
		{
			printf("%c",karakter);//karakteri yazar
			karakter = fgetc(dosya);//karakteri okur
			//BURADA DOSYADAKÝ SATIR SAYISINI BULUYORUZ VE YAZIYORUZ.
			if(karakter ==')') // eðer karakter ')' ise satýrý yaz . 
			{
				satir++;
				printf("%d",satir);
			}
		}
	}else
	{
		printf("dosya bulunamadi...");
		fclose(dosya);
	}
	
		printf("\n--------------------------------------------\n");	
			printf("+ - Uye Ekleme\n");
			printf("- - Uye Silme\n");
			printf("* - Uye Guncelleme\n");
			printf("0 - Cikis\n");
	fclose(dosya);
}

void UyeSil(){
	FILE *dosya, *dosyayeni;   
	dosyayeni = fopen("yeniuyedatabase.txt","w");//'yeniuyedatabase.txt' dosyamýzý yazma modunda açýyoruz.
	dosya = fopen("uyedatabase.txt","r");//'uyedatabase.txt' dosyamýzý okuma modunda açýyoruz.
	int satir=0;
	printf("hangi satirdaki uyeyi silmek istiyorsunuz: ");
	scanf("%d",&satir);//kullanýcýdan silinecek satýrý alýyoruz.
	
	char line[256];
	int i=0;
	
	while(fgets(line, sizeof(line),dosya))
	{
		i++;
		if (i != satir)
			fputs(line, dosyayeni);//'uyedatabase.txt' dosyadaki verileri yeni dosyaya yazýyoruz.
	}
	
	fclose(dosya);
	fclose(dosyayeni);
	remove("uyedatabase.txt");//'uyedatabase.txt' dosyasýný siliyoruz.
	rename("yeniuyedatabase.txt", "uyedatabase.txt");//'yeniuyedatabase.txt' dosyamýzýn adýný 'uyedatabase' olarak deðiþtiriyoruz.
	printf("kayit silindi. bir tusa basin.\n");
}

	void UyeGuncelle(){
	char adi[20];
	char soyadi[20];
	char cinsiyetString[10];
	char cinsiyetChar;
	char tc[12],tcAra[12];
	int yas,gun,ay,yil,cnsyt,boy,hocaSec,programSec,satir;
	float kilo;
	bool cinsiyetKontrol=true,yasKontrol=true;	
	
	FILE *dosya, *dosyayeni;   
	dosya = fopen("uyedatabase.txt","r");
	dosyayeni = fopen("yeniuyedatabase.txt","w");
	//yeniuyedatabase.txt ADINDA YENÝ BÝR TXT DOSYASI AÇIP GÜNCELLENÝCEK SATIRDAKÝ VERÝLERÝ ALIP YENÝ TXT DOSYAMIZA AYNI SATIRA ALDIÐIMIZ VERÝLERÝ GÝRÝYORUZ
	printf("Hangi satiri guncelleyeceksiniz: ");
	scanf("%d",&satir);

		printf("-------------------Uye Güncelleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("Güncellemek etmek istediginiz uyenin Tc nosunu giriniz:");
			scanf("%s",&tc);
			printf("\nGüncellemek etmek istediginiz uyenin adini giriniz:");
			scanf("%s",&adi);
			printf("Güncellemek etmek istediginiz uyenin soyadini giriniz:");
			scanf("%s",&soyadi);
		do{
			printf("Güncellemek etmek istediginiz uyenin cinsiyetini seciniz(E/K):");
			scanf("%s",&cinsiyetChar);
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				strcpy(cinsiyetString, "Erkek");
				cinsiyetKontrol=false;
			}else if(cinsiyetChar == 'k'|| cinsiyetChar == 'K'){
				strcpy(cinsiyetString, "Kadin");
				cinsiyetKontrol=false;
			}else{
				printf("Lutfen E veya K harflerinden biriniz yaziniz.\n");
				cinsiyetKontrol=true;
			}	
		}while(cinsiyetKontrol);

			printf("Güncellemek etmek istediginiz uyenin yasini giriniz:");
			scanf("%d",&yas);
			printf("Güncellemek etmek istediginiz uyenin boyunu giriniz(orn:185):");
			scanf("%d",&boy);
			printf("Güncellemek etmek istediginiz uyenin kilosunu giriniz(orn:75.8):");
			scanf("%f",&kilo);
			printf("Güncellemek etmek istediginiz uyenin giris tarihini giriniz =>\n");
			printf("Gun: ");
			scanf("%d",&gun);
			printf("Ay: ");
			scanf("%d",&ay);
			printf("Yil: ");
			scanf("%d",&yil);
			
			
			ProgramListele();
			/*----------------------------------------ÝDEAL KÝLONUN HESAPLANDIÐI BÖLÜM----------------------------------------*/
			float erkek=0.9,kadin=0.8,idealKilo,fark;
			
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				idealKilo=(boy-100+yas/10)*erkek;
				fark=kilo - idealKilo;
			}else{
				float idealKilo=(boy-100+yas/10)*kadin;
				float fark=(kilo - idealKilo);
				
			}
			if(fark<0) printf("Zayifsiniz.kilo alma programini secmeniz onerilir.");
				else if(fark>=0 && fark<=10) printf("Normal Kilolusunuz.Kas kutlesi kazanma programini secmeniz onerilir ");
				else if(fark>=11 && fark<=20) printf("Fazla Kilolusunuz.Kilo verme programi veya kas kutlesi programini secmeniz onerilir");
				else if(fark>=21 && fark<=29) printf("Obezsiniz.Kilo verme programini secmeniz onerilir");
				else if(fark>=30) printf("ileri Derecede Obezsiniz.Kilo verme programini secmeniz onerilir");
				else printf("Kilo Hesaplanamadi");
			
			printf("\n\nProgram seciniz:");
			scanf("%d",&programSec);
			
			HocaListele();
			printf("Hoca seciniz:");
			scanf("%d",&hocaSec);
			
			
			
			
			
			
			
	
	
	char line[250];
	int i=0;
	
	while(fgets(line, sizeof(line),dosya))
	{
		i++;
		if (i != satir)//güncellemek istediðimiz satýra gelip gelmediðimizi kontrol ediyor güncellemek istemediðimiz satýra gelmemiþse if bloðunun içindeki kodlarý çalýþtýrýyor
			fputs(line, dosyayeni);//eski dosyanýn satýrýndaki bütün karakterleri yeni dosyaya yazýyor
	    else{
		
			fprintf(dosyayeni,"() %s - %s - %s - %d -%s- %d - %f - Kayit Tarihi: %d / %d / %d | Ideal Kilo: %.2f | Hoca Secimi: %d | Program Secimi: %d \n",tc,adi,soyadi, yas, cinsiyetString,boy,kilo,gun,ay,yil,idealKilo,hocaSec,programSec);
			
			}
	}
	
	fclose(dosya);
	fclose(dosyayeni);
	remove("uyedatabase.txt");//eski dosyayý siliyor
	rename("yeniuyedatabase.txt", "uyedatabase.txt");//yeni dosyanýn adýný eski dosyanýn adýyla deðiþtiriyor.
	printf("Kayit guncellendi....\n");
	}
	
void HocaEkle(){
		
		char adi[20];
		char soyadi[20];
		char cinsiyetString[10];
		char cinsiyetChar;
		char tc[12],tcAra[12];
		bool cinsiyetKontrol=true,yasKontrol=true;	
		FILE *dosya;
		dosya = fopen("hocadatabase.txt","a");
		if(dosya!=NULL)
		{
			printf("-------------------Hoca Ekleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("Kayit etmek istediginiz hoca Tc nosunu giriniz:");
			scanf("%s",&tc);
			printf("\nKayit etmek istediginiz hoca adini giriniz:");
			scanf("%s",&adi);
			printf("Kayit etmek istediginiz hoca soyadini giriniz:");
			scanf("%s",&soyadi);
			do{
				printf("Kayit etmek istediginiz hoca cinsiyetini seciniz(E/K):");
				scanf("%s",&cinsiyetChar);
				if(cinsiyetChar=='e'||cinsiyetChar=='E')
				{
					strcpy(cinsiyetString, "Erkek");
					cinsiyetKontrol=false;
				}else if(cinsiyetChar == 'k'|| cinsiyetChar == 'K'){
					strcpy(cinsiyetString, "Kadin");
					cinsiyetKontrol=false;
				}else{
					printf("Lutfen E veya K harflerinden biriniz yaziniz.\n");
					cinsiyetKontrol=true;
				}	
			}while(cinsiyetKontrol);
			
			fprintf(dosya,"() %s - %s - %s - %s \n",tc,adi,soyadi,cinsiyetString);
			fclose(dosya);
		
		}else{
			printf("Dosya Bulunamadý");
			fclose(dosya);
		}	
	}
void HocaSil(){
	FILE *dosya, *dosyayeni;   
	dosyayeni = fopen("yenihocadatabase.txt","w");//'yeniuyedatabase.txt' dosyamýzý yazma modunda açýyoruz.
	dosya = fopen("hocadatabase.txt","r");//'uyedatabase.txt' dosyamýzý okuma modunda açýyoruz.
	int satir=0;
	printf("hangi satirdaki hocayi silmek istiyorsunuz: ");
	scanf("%d",&satir);//kullanýcýdan silinecek satýrý alýyoruz.
	
	char line[256];
	int i=0;
	
	while(fgets(line, sizeof(line),dosya))
	{
		i++;
		if (i != satir)
			fputs(line, dosyayeni);//'uyedatabase.txt' dosyadaki verileri yeni dosyaya yazýyoruz.
	}
	
	fclose(dosya);
	fclose(dosyayeni);
	remove("hocadatabase.txt");//'uyedatabase.txt' dosyasýný siliyoruz.
	rename("yenihocadatabase.txt", "hocadatabase.txt");//'yeniuyedatabase.txt' dosyamýzýn adýný 'uyedatabase' olarak deðiþtiriyoruz.
	printf("kayit silindi. bir tusa basin.\n");
		
		
	}
void HocaListele(){
	FILE *dosya;
	int satir=0;
	dosya = fopen("hocadatabase.txt","r");//'hocadatabase.txt'dosyamýzý okuma modunda açýyoruz.
	char karakter,sonraki;
	if(dosya != NULL)//dosyanýn olup olmadýðýný kontrol ettiðimiz bölüm
	{
		karakter = fgetc(dosya);
		while(!feof(dosya))//dosyanýn içindeki bütün karakterleri döngü ile aldýðýmýz bölüm !feof fonksiyonu dosyanýn sonuna gelinip gelinmediðini kontrol eder.
		{
			printf("%c",karakter);//karakteri yazar
			karakter = fgetc(dosya);//karakteri okur
			//BURADA DOSYADAKÝ SATIR SAYISINI BULUYORUZ VE YAZIYORUZ.
			if(karakter ==')') // eðer karakter ')' ise satýrý yaz . 
			{
				satir++;
				printf("%d",satir);
			}
		}
	}else
	{
		printf("dosya bulunamadi...");
		fclose(dosya);
	}
	
		
	fclose(dosya);
}
void HocaGuncelle(){
		char adi[20];
		char soyadi[20];
		char cinsiyetString[10];
		char cinsiyetChar;
		char tc[12],tcAra[12];
		bool cinsiyetKontrol=true,yasKontrol=true;	
		int satir=0;
		FILE *dosya, *dosyayeni;   
		dosya = fopen("hocadatabase.txt","r");
		dosyayeni = fopen("yenihocadatabase.txt","w");
	
		printf("Hangi satiri guncelleyeceksiniz: ");
		scanf("%d",&satir);

		printf("-------------------Hoca Güncelleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("Güncellemek etmek istediginiz hoca Tc nosunu giriniz:");
			scanf("%s",&tc);
			printf("\nGüncellemek etmek istediginiz hoca adini giriniz:");
			scanf("%s",&adi);
			printf("Güncellemek etmek istediginiz hoca soyadini giriniz:");
			scanf("%s",&soyadi);
		do{
			printf("Güncellemek etmek istediginiz hoca cinsiyetini seciniz(E/K):");
			scanf("%s",&cinsiyetChar);
			if(cinsiyetChar=='e'||cinsiyetChar=='E')
			{
				strcpy(cinsiyetString, "Erkek");
				cinsiyetKontrol=false;
			}else if(cinsiyetChar == 'k'|| cinsiyetChar == 'K'){
				strcpy(cinsiyetString, "Kadin");
				cinsiyetKontrol=false;
			}else{
				printf("Lutfen E veya K harflerinden biriniz yaziniz.\n");
				cinsiyetKontrol=true;
			}	
		}while(cinsiyetKontrol);

		char line[100];
		int i=0;
		while(fgets(line, sizeof(line),dosya))
		{
			i++;
			if (i != satir)
				fputs(line, dosyayeni);
		    else{
			
				fprintf(dosyayeni,"() %s - %s - %s - %s - \n",tc,adi,soyadi, cinsiyetString);
				}
		}
		fclose(dosya);
		fclose(dosyayeni);
		remove("hocadatabase.txt");
		rename("yenihocadatabase.txt", "hocadatabase.txt");
		printf("Kayit guncellendi....\n");
		}
void ProgramListele(){
	FILE *dosya;
	int satir=0;
	dosya = fopen("programdatabase.txt","r");//'hocadatabase.txt'dosyamýzý okuma modunda açýyoruz.
	char karakter;
	if(dosya != NULL)//dosyanýn olup olmadýðýný kontrol ettiðimiz bölüm
	{
		karakter = fgetc(dosya);
		while(!feof(dosya))//dosyanýn içindeki bütün karakterleri döngü ile aldýðýmýz bölüm !feof fonksiyonu dosyanýn sonuna gelinip gelinmediðini kontrol eder.
		{
			printf("%c",karakter);//karakteri yazar
			karakter = fgetc(dosya);//karakteri okur
			//BURADA DOSYADAKÝ SATIR SAYISINI BULUYORUZ VE YAZIYORUZ.
			if(karakter ==')') // eðer karakter ')' ise satýrý yaz . 
			{
				satir++;
				printf("%d",satir);
			}
		}
	}else
	{
		printf("dosya bulunamadi...");
		fclose(dosya);
	}
	
	
	fclose(dosya);
}
void ProgramEkle(){
	
		char ProgramAdi[20];	
		FILE *dosya;
		dosya = fopen("programdatabase.txt","a");
		if(dosya!=NULL)
		{
			printf("-------------------Program Ekleme Ekranina Hosgeldiniz-------------------\n\n");
			printf("\nKayit etmek istediginiz program adini giriniz:");
			scanf("%s",&ProgramAdi);
			fprintf(dosya,"() %s \n",ProgramAdi);
			fclose(dosya);
		
		}else{
			printf("Dosya Bulunamadý");
			fclose(dosya);
		}
	
}

