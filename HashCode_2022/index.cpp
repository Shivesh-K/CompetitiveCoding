#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define int long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

ifstream input("c_collaboration.in.txt");
ofstream output("c_collaboration.out.txt");

struct Skill
{
    int id;
    string name;
    int level;

    Skill(int _id, string _name, int _level)
    {
        id = _id;
        name = _name;
        level = _level;
    }

    bool operator<(const Skill &other)
    {
        return this->name == other.name ? this->level <= other.level : this->name <= other.name;
    }
};

struct Contributor
{
    int id;
    string name;
    map<string, int> skills;
    int freeAfter;

    Contributor(int _id, string _name)
    {
        id = _id;
        name = _name;
        // skills.clear();
        freeAfter = 0;
    }
};

struct Project
{
    int id;
    string name;
    int duration, score, bestBefore;
    vector<Skill> roles;

    Project(int _id, string _name, int _duration, int _score, int _bestBefore)
    {
        id = _id;
        name = _name;
        duration = _duration;
        score = _score;
        bestBefore = _bestBefore;
    }

    Project(const Project &pr)
    {
        id = pr.id;
        name = pr.name;
        duration = pr.duration;
        score = pr.score;
        bestBefore = pr.bestBefore;
        for (auto role : pr.roles)
            roles.push_back(role);
    }

    bool operator<(const Project &other)
    {
        if (this->score != other.score)
            return this->score > other.score;
        else if (this->bestBefore != other.bestBefore)
            return this->bestBefore <= this->bestBefore;
        else
            return this->duration < other.duration;
    }
};

struct AssignedProject : public Project
{
    vector<Contributor *> workers;

    AssignedProject(const Project &pr) : Project(pr)
    {
        workers = vector<Contributor *>(pr.roles.size(), nullptr);
    }
};

int c, p;
vector<Project> projects;
vector<Contributor> contributors;

map<string, set<pair<int, Contributor *>>> skillsToContributors;

void compute()
{

    input >> c >> p;

    for (int i = 0; i < c; ++i)
    {
        string s;
        int n;
        input >> s >> n;
        Contributor con(i, s);

        for (int j = 0; j < n; ++j)
        {
            string t;
            int l;
            input >> t >> l;
            Skill sk(j, t, l);
            con.skills[t] = l;
            skillsToContributors[t].insert({l, &con});
        }

        contributors.push_back(con);
    }

    for (int i = 0; i < p; ++i)
    {
        string name;
        int d, s, b, r;
        input >> name >> d >> s >> b >> r;
        Project proj(i, name, d, s, b);

        for (int j = 0; j < r; ++j)
        {
            string t;
            int l;
            input >> t >> l;
            Skill sk(j, t, l);
            proj.roles.push_back(sk);
        }

        projects.push_back(proj);
    }

    sort(projects.begin(), projects.end());

    vector<AssignedProject> assignedProjects;

    for (auto pr : projects)
    {
        AssignedProject ap(pr);
        sort(pr.roles.begin(), pr.roles.end());

        auto copy = skillsToContributors;
        map<string, bool> assignedContributors;
        bool fl = true;

        for (int i = 0; i < ap.roles.size(); ++i)
        {
            auto role = ap.roles[i];

            auto it = copy[role.name].lower_bound({role.level, nullptr});
            if (it != copy[role.name].end())
            {
                if (!assignedContributors[it->second->name])
                {
                    ap.workers[role.id] = it->second;
                    assignedContributors[it->second->name] = true;
                }
                else
                {
                    --i;
                }
                copy[role.name].erase(it);
            }
            else
            {
                fl = false;
                break;
            }
        }

        if (fl)
        {
            // cout << "Hey\n";
            for (auto role : ap.roles)
                (ap.workers[role.id]->skills[role.name])++;
            assignedProjects.push_back(ap);
        }
    }

    output << assignedProjects.size() << "\n";
    for (auto ap : assignedProjects)
    {
        output << ap.name << "\n";
        for (auto w : ap.workers)
            output << w->name << " ";
        output << "\n";
    }

    input.close();
    output.close();
}

int32_t main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("cout.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    compute();
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}