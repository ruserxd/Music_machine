//播放音樂需要用到函式庫
#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#include"resource.h"
#pragma comment (lib, "winmm.lib")
//
#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<algorithm>


using namespace std;

struct music_robot {
    string song_name;
    int number;
}typedef music;

vector<music> initial_music() {
    vector<string> setting_song = { "也許你不在","你好不好","怎麼了"};
    int num = setting_song.size();
    vector<music>temp(num);
    for(int i=0;i<num;i++){
        temp[i].song_name = setting_song[i];
        temp[i].number = i;
        //cout<<"已載入"<<temp[i].song_name<<"編號:"<<temp[i].number<<endl;
    }
    return temp;
}

void out_how_many_song(vector<music>musicsong) {
    int len = musicsong.size();
    for (int i = 0; i < len; i++) {
        cout << "編號:" << musicsong[i].number + 1 << " 歌名:" << musicsong[i].song_name << endl;
    }
}

void choose_song(vector<music>musicsong) {
    int number_by_song;
    cout << "請問想要聽哪個編號的歌呢?__";
    cin >> number_by_song;
    if (number_by_song <= musicsong.size()) {
        PlaySound(MAKEINTRESOURCE(IDR_WAVE1 + number_by_song - 1), NULL, SND_RESOURCE | SND_ASYNC);
        system("pause");
    }
}
int main() {
    string s;
    vector<music>musicsong;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s == "呼叫機器人" || s == "call") {
        musicsong = initial_music();
        out_how_many_song(musicsong);
        choose_song(musicsong);
    }
    else {
        cout << "這是一個錯誤的指令";
    }
    return 0;
}
