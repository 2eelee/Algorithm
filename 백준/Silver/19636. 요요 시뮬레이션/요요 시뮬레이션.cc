#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
    int w0, i0, t, d, i, a; // W0, I0, T, D, I, A
    
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;
    
    int weight = w0, bmr = i0, threshold = t;
    int diet_EIntake = i, diet_AM = a;
    int dead_or_not=1;
    
    
    for(int j=0; j<d; j++){ // 일일 기초대사량 변화를 고려하지 않는 다이어트의 경우
    
        weight += ( diet_EIntake - (bmr + diet_AM));
        
        if( weight<=0 || bmr<=0 ){ // 체중이나 일일기초대사량이 0 이하일 경우 데시 사망 
            cout << "Danger Diet" << "\n";
            dead_or_not = 0;
            break;
        }
    }
    
    if(dead_or_not != 0) cout << weight << " " << bmr << "\n"; // 다이어트 후 예상 체중과 일일 기초 대사량 출력
    
    
    
    weight = w0, dead_or_not = 1; // 체중 초기화 
    
    for(int j=0; j<d; j++){ // 일일 기초대사량 변화를 고려하는 다이어트의 경우
    
        int vari = ( diet_EIntake - (bmr + diet_AM) ); // vari(체중증감량) 만큼 체중 변화 
        weight += vari;
        
        if(abs(vari) > threshold){ // 체중증감량 > T 라면, 일일 기초대사량 변화 
            bmr += floor(vari/2.0);
        }
        
        if( weight<=0 || bmr<=0 ){ // 체중이나 일일기초대사량이 0 이하일 경우 데시 사망 
            cout << "Danger Diet" << "\n";
            dead_or_not = 0;
            break;
        }
    }
    
    if(dead_or_not != 0) {
        cout << weight << " " << bmr << " "; // 다이어트 후 예상 체중과 일일 기초 대사량 출력
        if(bmr < i0) cout << "YOYO";
        else cout << "NO";
    
    }
}