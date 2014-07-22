// Author: WangZhan -> wangzhan.1985@gmail.com
#pragma once
#include "BasicTypes.h"
#include "MessagePump.h"


class MessagePumpForUI : public MessagePumpForMsg
{
public:
    MessagePumpForUI();
    ~MessagePumpForUI();

    virtual void ScheduleWork();
    virtual void ScheduleDelayedWork(DWORD dwDelayedWorkTime);

private:
    virtual void DoRunLoop();

    void InitMessageWnd();
    void ClearMessageWnd();

    bool ProcessNextWindowsMessage();
    // ����have_work_msgʱ���ȴ���һ��ϵͳ��Ϣ����ֹhave_work_msg������Ϣѭ��
    bool ProcessPumpReplacementMessage();
    bool ProcessMessageHelp(MSG &msg);

    void HandleWorkMessage();
    void HandleTimerMessage();

    void WaitForWork();

    static LRESULT CALLBACK WndProcThunk(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

    HWND m_hMsgWnd;

    DISALLOW_COPY_AND_ASSIGN(MessagePumpForUI);
};
