// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     int bt[20], p[20], wt[20], tat[20], pr[20];
//     int i, j, n, total = 0, pos, temp;
//     float avg_wt, avg_tat;
//     string name, admissionNo;

//     cout << "Enter your name: ";
//     getline(cin, name);

//     cout << "Enter your admission number: ";
//     getline(cin, admissionNo);

//     cout << "\nEnter Total Number of Processes: ";
//     cin >> n;

//     cout << "\nEnter Burst Time and Priority\n";

//     for (i = 0; i < n; i++)
//     {
//         cout << "\nP[" << i + 1 << "]\n";

//         cout << "Burst Time: ";
//         cin >> bt[i];

//         cout << "Priority: ";
//         cin >> pr[i];

//         p[i] = i + 1;
//     }

//     // Sort processes by priority (smaller number = higher priority)
//     for (i = 0; i < n; i++)
//     {
//         pos = i;

//         for (j = i + 1; j < n; j++)
//         {
//             if (pr[j] < pr[pos])
//             {
//                 pos = j;
//             }
//         }

//         temp = pr[i];
//         pr[i] = pr[pos];
//         pr[pos] = temp;

//         temp = bt[i];
//         bt[i] = bt[pos];
//         bt[pos] = temp;

//         temp = p[i];
//         p[i] = p[pos];
//         p[pos] = temp;
//     }

//     wt[0] = 0;

//     for (i = 1; i < n; i++)
//     {
//         wt[i] = 0;

//         for (j = 0; j < i; j++)
//         {
//             wt[i] += bt[j];
//         }

//         total += wt[i];
//     }

//     avg_wt = static_cast<float>(total) / n;
//     total = 0;

//     cout << "\n\nName: " << name;
//     cout << "\nAdmission No.: " << admissionNo;

//     cout << "\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time";

//     for (i = 0; i < n; i++)
//     {
//         tat[i] = bt[i] + wt[i];
//         total += tat[i];

//         cout << "\nP[" << p[i] << "]\t"
//              << bt[i] << "\t\t"
//              << wt[i] << "\t\t"
//              << tat[i];
//     }

//     avg_tat = static_cast<float>(total) / n;

//     cout << "\n\nAverage Waiting Time = " << avg_wt;
//     cout << "\nAverage Turnaround Time = " << avg_tat << endl;

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int count, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    int at[10], bt[10], rt[10];

    string name, admissionNo;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your admission number: ";
    getline(cin, admissionNo);

    cout << "\nEnter Total Process: ";
    cin >> n;

    remain = n;

    for (count = 0; count < n; count++)
    {
        cout << "Enter Arrival Time and Burst Time for Process Number "
             << count + 1 << ": ";

        cin >> at[count] >> bt[count];
        rt[count] = bt[count];
    }

    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    // Display student details above the output
    cout << "\n----------------------------------------";
    cout << "\nName: " << name;
    cout << "\nAdmission No.: " << admissionNo;
    cout << "\n----------------------------------------";

    cout << "\n\nProcess\t| Turnaround Time | Waiting Time\n";

    for (time = 0, count = 0; remain != 0;)
    {
        if (rt[count] <= time_quantum && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }

        if (rt[count] == 0 && flag == 1)
        {
            remain--;

            cout << "\nP[" << count + 1 << "]\t| "
                 << time - at[count] << "\t\t | "
                 << time - at[count] - bt[count];

            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];

            flag = 0;
        }

        if (count == n - 1)
        {
            count = 0;
        }
        else if (at[count + 1] <= time)
        {
            count++;
        }
        else
        {
            count = 0;
        }
    }

    cout << "\n\nAverage Waiting Time = "
         << static_cast<float>(wait_time) / n;

    cout << "\nAverage Turnaround Time = "
         << static_cast<float>(turnaround_time) / n << endl;

    return 0;
}