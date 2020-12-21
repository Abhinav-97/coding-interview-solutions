                {
                    st.push(curr);
                    curr = curr->left;
                }
                else{
                    if(!st.empty())
                    {
                        TreeNode* topVal1 = st.top();
                        st.pop();
                        val1 = topVal1->val;
                        curr = topVal1->right;
                    }
                    done1 = true;
                }
            }
            
            while(!done2)
            {
                if(curr2 != NULL)
                {
                    revserseSt.push(curr2);
                    curr2 = curr2->right;
                }
                else{
                    if(!revserseSt.empty())
                    {
                        TreeNode* topVal2 = revserseSt.top();
                        revserseSt.pop();
                        val2 = topVal2->val;
                        curr2 = topVal2->left;
                    }
                    done2 = true;
                }
            }
            if((val1 != val2) && (val1 + val2) == k)
            {
                return true;
            }
            else if(val1 + val2 < k)
            {
                done1 = false;
            }
            else{
                done2 = false;
            }
            
