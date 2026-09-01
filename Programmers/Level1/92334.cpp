/*
    신고 결과 받기
    https://school.programmers.co.kr/learn/courses/30/lessons/92334
*/

#include "stdc++.h"
#include <sstream>

using namespace std;

struct ReportInfo {
    string sUserID;
    vector<string> slReportID;
};
vector<ReportInfo> lReportInfo;
vector<string> slBlockID;

// id_list  유저 ID
// report   유저가 신고한 ID
// k        게시판 이용 정지 기준
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> mpCountReport;
    
    // init
    for ( const auto &id : id_list ) {
        ReportInfo tempReport;
        tempReport.sUserID = id;
        lReportInfo.push_back(tempReport);
        mpCountReport.insert( { id, 0 } );
    }
    
    // 신고 목록 중복 제거
    set<string> slDdeduplicateReport;
    for ( const auto &userReport : report ) {
        slDdeduplicateReport.insert(userReport);
    }
    
    // 신고 내용 파싱
    for ( const auto &userReport : slDdeduplicateReport) {
        stringstream ss(userReport);
        string sUserID;
        ss >> sUserID;
        for ( auto &reportInfo : lReportInfo ) {
            if ( sUserID == reportInfo.sUserID ) {
                string sReportID;
                ss >> sReportID;
                reportInfo.slReportID.push_back( sReportID );
                
                mpCountReport[sReportID]++;
                
                break;
            }
        }
    }
    
    // 정지 유저 선별
    for ( const auto &countReport : mpCountReport ) {
        if ( countReport.second >= k ) {
            slBlockID.push_back( countReport.first );
        }
    }
    
    // 메일 발송 카운트
    for ( auto &reportInfo : lReportInfo ) {
        int nMailCount = 0;
        for ( const auto &blockID : slBlockID) {
            if ( find( reportInfo.slReportID.begin(), reportInfo.slReportID.end(), blockID ) != reportInfo.slReportID.end() ) {
                nMailCount++;
            }
        }
        answer.push_back(nMailCount);
    }
    
    return answer;
}