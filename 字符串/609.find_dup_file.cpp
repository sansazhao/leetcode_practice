class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vector<string>> content_map;
        for (string &path : paths)
        {
            stringstream ss(path);
            string dir, tmp;
            ss >> dir;
            while (ss >> tmp)
            {
                string filename, content;
                int i = 0;
                while (tmp[i] != '(')
                    filename += tmp[i++];
                i++;
                while (tmp[i] != ')')
                    content += tmp[i++];
                content_map[content].push_back(dir + '/' + filename);
            }
        }
        vector<vector<string>> ans;
        for (auto [content, files] : content_map)
        {
            if (files.size() > 1)
                ans.push_back(files);
        }
        return ans;
    }
};