class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        char direction='N';
        for(int i=0;i<instructions.length();i++)
        {
            // cout<<direction<<endl;
            if(instructions[i] == 'G')
            {
                if(direction == 'N')
                {
                    y += 1;
                }
                if(direction == 'S')
                {
                    y -= 1 ;
                }
                if(direction == 'W')
                {
                    x -= 1;
                }
                if(direction == 'E')
                {
                    x += 1;
                }
            }
            else{
                char incoming = instructions[i];
                if(direction == 'N'){
                    direction = incoming == 'L' ? 'W' : 'E';
                }
                else if(direction == 'W'){
                    direction = incoming == 'L' ? 'S' : 'N';
                }
                else if(direction == 'S'){
                    direction = incoming == 'L' ? 'E' : 'W';
                }
                else{
                    direction = incoming == 'L' ? 'N' : 'S';
                }
            }
            // cout<<direction<<endl;
        }
        // cout<<direction<<x<<y;
        if(direction != 'N' || (x == 0 && y == 0))
        {
            return true;
        }
        return false;
    }
};