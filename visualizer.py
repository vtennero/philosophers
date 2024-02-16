import matplotlib.pyplot as plt
import pandas as pd
from matplotlib.colors import ListedColormap

# Sample data snippet
data = """
0 2 has taken a fork
0 2 has taken a fork
0 4 has taken a fork
0 4 has taken a fork
0 4 is eating
0 6 has taken a fork
0 8 has taken a fork
0 2 is eating
0 6 has taken a fork
0 6 is eating
0 8 has taken a fork
0 8 is eating
0 10 has taken a fork
0 10 has taken a fork
0 10 is eating
0 12 has taken a fork
0 12 has taken a fork
0 12 is eating
0 14 has taken a fork
0 14 has taken a fork
0 14 is eating
0 16 has taken a fork
0 16 has taken a fork
0 16 is eating
0 18 has taken a fork
0 18 has taken a fork
0 18 is eating
0 20 has taken a fork
0 20 has taken a fork
0 20 is eating
0 22 has taken a fork
0 22 has taken a fork
0 22 is eating
0 24 has taken a fork
0 24 has taken a fork
0 24 is eating
0 26 has taken a fork
0 26 has taken a fork
0 26 is eating
0 28 has taken a fork
0 28 has taken a fork
0 28 is eating
0 30 has taken a fork
0 30 has taken a fork
0 30 is eating
0 32 has taken a fork
0 32 has taken a fork
0 32 is eating
0 34 has taken a fork
0 34 has taken a fork
0 34 is eating
0 36 has taken a fork
0 36 has taken a fork
0 36 is eating
0 38 has taken a fork
0 38 has taken a fork
0 38 is eating
0 40 has taken a fork
0 40 has taken a fork
0 40 is eating
0 42 has taken a fork
0 42 has taken a fork
0 42 is eating
0 44 has taken a fork
0 44 has taken a fork
0 44 is eating
0 46 has taken a fork
0 46 has taken a fork
0 46 is eating
0 48 has taken a fork
0 48 has taken a fork
0 48 is eating
0 50 has taken a fork
0 50 has taken a fork
0 50 is eating
0 52 has taken a fork
0 52 has taken a fork
0 52 is eating
0 54 has taken a fork
0 54 has taken a fork
0 54 is eating
0 56 has taken a fork
0 56 has taken a fork
0 56 is eating
0 58 has taken a fork
0 58 has taken a fork
0 58 is eating
1 60 has taken a fork
1 60 has taken a fork
1 60 is eating
1 62 has taken a fork
1 62 has taken a fork
1 62 is eating
1 64 has taken a fork
1 64 has taken a fork
1 64 is eating
1 66 has taken a fork
1 66 has taken a fork
1 66 is eating
1 68 has taken a fork
1 68 has taken a fork
1 68 is eating
1 70 has taken a fork
1 70 has taken a fork
1 70 is eating
1 72 has taken a fork
1 72 has taken a fork
1 72 is eating
1 74 has taken a fork
1 74 has taken a fork
1 74 is eating
1 76 has taken a fork
1 76 has taken a fork
1 76 is eating
1 78 has taken a fork
1 78 has taken a fork
1 78 is eating
1 80 has taken a fork
1 80 has taken a fork
1 80 is eating
1 82 has taken a fork
1 82 has taken a fork
1 82 is eating
1 84 has taken a fork
1 84 has taken a fork
1 84 is eating
1 86 has taken a fork
1 86 has taken a fork
1 86 is eating
1 88 has taken a fork
1 88 has taken a fork
1 88 is eating
1 90 has taken a fork
1 90 has taken a fork
1 90 is eating
1 92 has taken a fork
1 92 has taken a fork
1 92 is eating
1 94 has taken a fork
1 94 has taken a fork
1 94 is eating
1 96 has taken a fork
1 96 has taken a fork
1 96 is eating
1 98 has taken a fork
1 98 has taken a fork
1 98 is eating
1 100 has taken a fork
1 100 has taken a fork
1 100 is eating
1 1 has taken a fork
1 102 has taken a fork
1 102 has taken a fork
1 102 is eating
1 106 has taken a fork
1 106 has taken a fork
1 106 is eating
1 108 has taken a fork
1 108 has taken a fork
1 108 is eating
1 110 has taken a fork
1 110 has taken a fork
1 110 is eating
1 112 has taken a fork
1 112 has taken a fork
1 112 is eating
1 114 has taken a fork
1 114 has taken a fork
1 114 is eating
1 116 has taken a fork
1 116 has taken a fork
1 116 is eating
1 118 has taken a fork
1 118 has taken a fork
1 118 is eating
1 120 has taken a fork
1 120 has taken a fork
1 120 is eating
1 122 has taken a fork
1 122 has taken a fork
1 122 is eating
1 124 has taken a fork
1 124 has taken a fork
1 124 is eating
1 126 has taken a fork
1 126 has taken a fork
1 126 is eating
1 128 has taken a fork
1 128 has taken a fork
1 128 is eating
1 130 has taken a fork
1 130 has taken a fork
1 130 is eating
1 132 has taken a fork
1 132 has taken a fork
1 132 is eating
1 134 has taken a fork
1 134 has taken a fork
1 134 is eating
1 136 has taken a fork
1 136 has taken a fork
1 136 is eating
1 138 has taken a fork
1 138 has taken a fork
1 138 is eating
1 140 has taken a fork
1 140 has taken a fork
1 140 is eating
1 142 has taken a fork
1 142 has taken a fork
1 142 is eating
1 144 has taken a fork
1 144 has taken a fork
1 144 is eating
1 146 has taken a fork
1 146 has taken a fork
1 146 is eating
1 148 has taken a fork
1 148 has taken a fork
1 148 is eating
1 150 has taken a fork
1 150 has taken a fork
1 150 is eating
1 152 has taken a fork
1 152 has taken a fork
1 152 is eating
2 154 has taken a fork
2 154 has taken a fork
2 154 is eating
2 156 has taken a fork
2 156 has taken a fork
2 156 is eating
2 158 has taken a fork
2 158 has taken a fork
2 158 is eating
2 160 has taken a fork
2 160 has taken a fork
2 160 is eating
2 105 has taken a fork
2 162 has taken a fork
2 162 has taken a fork
2 162 is eating
2 164 has taken a fork
2 164 has taken a fork
2 164 is eating
2 166 has taken a fork
2 166 has taken a fork
2 166 is eating
2 168 has taken a fork
2 168 has taken a fork
2 168 is eating
2 170 has taken a fork
2 170 has taken a fork
2 170 is eating
2 104 has taken a fork
2 172 has taken a fork
2 172 has taken a fork
2 172 is eating
2 174 has taken a fork
2 174 has taken a fork
2 174 is eating
2 176 has taken a fork
2 176 has taken a fork
2 176 is eating
2 178 has taken a fork
2 178 has taken a fork
2 178 is eating
2 180 has taken a fork
2 180 has taken a fork
2 180 is eating
2 182 has taken a fork
2 182 has taken a fork
2 182 is eating
2 184 has taken a fork
2 184 has taken a fork
2 184 is eating
2 186 has taken a fork
2 186 has taken a fork
2 186 is eating
2 188 has taken a fork
2 188 has taken a fork
2 188 is eating
2 190 has taken a fork
2 190 has taken a fork
2 190 is eating
2 192 has taken a fork
2 192 has taken a fork
2 192 is eating
2 194 has taken a fork
2 194 has taken a fork
2 194 is eating
2 196 has taken a fork
2 196 has taken a fork
2 196 is eating
2 198 has taken a fork
2 198 has taken a fork
2 198 is eating
2 200 has taken a fork
200 56 is sleeping
200 58 is sleeping
200 57 has taken a fork
200 57 has taken a fork
200 57 is eating
200 4 is sleeping
200 10 is sleeping
200 2 is sleeping
200 1 has taken a fork
200 1 is eating
200 3 has taken a fork
200 3 has taken a fork
200 5 has taken a fork
200 59 has taken a fork
200 3 is eating
200 11 has taken a fork
200 40 is sleeping
200 41 has taken a fork
200 42 is sleeping
200 41 has taken a fork
200 41 is eating
200 43 has taken a fork
200 22 is sleeping
200 54 is sleeping
200 48 is sleeping
200 55 has taken a fork
200 55 has taken a fork
200 26 is sleeping
200 27 has taken a fork
200 23 has taken a fork
200 8 is sleeping
200 50 is sleeping
200 18 is sleeping
200 9 has taken a fork
200 9 has taken a fork
200 9 is eating
200 20 is sleeping
200 25 has taken a fork
200 25 has taken a fork
200 47 has taken a fork
200 47 has taken a fork
200 47 is eating
200 28 is sleeping
200 11 has taken a fork
200 11 is eating
200 49 has taken a fork
200 49 has taken a fork
200 49 is eating
200 6 is sleeping
200 13 has taken a fork
200 31 has taken a fork
200 31 has taken a fork
200 31 is eating
200 5 has taken a fork
200 5 is eating
200 55 is eating
200 34 is sleeping
200 29 has taken a fork
200 29 has taken a fork
200 29 is eating
200 52 is sleeping
200 27 has taken a fork
200 27 is eating
200 53 has taken a fork
200 53 has taken a fork
200 53 is eating
200 35 has taken a fork
200 35 has taken a fork
200 35 is eating
200 17 has taken a fork
200 17 has taken a fork
200 17 is eating
200 33 has taken a fork
200 33 has taken a fork
200 33 is eating
200 36 is sleeping
200 15 has taken a fork
200 15 has taken a fork
200 15 is eating
200 37 has taken a fork
200 37 has taken a fork
200 37 is eating
200 44 is sleeping
200 19 has taken a fork
200 19 has taken a fork
200 19 is eating
200 43 has taken a fork
200 43 is eating
200 25 is eating
200 45 has taken a fork
200 45 has taken a fork
200 12 is sleeping
200 30 is sleeping
200 7 has taken a fork
200 7 has taken a fork
200 7 is eating
200 32 is sleeping
200 51 has taken a fork
200 51 has taken a fork
200 51 is eating
200 14 is sleeping
200 23 has taken a fork
200 23 is eating
200 46 is sleeping
200 24 is sleeping
200 21 has taken a fork
200 21 has taken a fork
200 21 is eating
200 38 is sleeping
200 39 has taken a fork
200 39 has taken a fork
200 39 is eating
200 45 is eating
200 13 has taken a fork
200 13 is eating
200 16 is sleeping
201 136 is sleeping
201 84 is sleeping
201 137 has taken a fork
201 116 is sleeping
201 85 has taken a fork
201 82 is sleeping
201 83 has taken a fork
201 83 has taken a fork
201 83 is eating
201 117 has taken a fork
201 109 has taken a fork
201 108 is sleeping
201 118 is sleeping
201 119 has taken a fork
201 117 has taken a fork
201 117 is eating
201 148 is sleeping
201 88 is sleeping
201 89 has taken a fork
201 101 has taken a fork
201 102 is sleeping
201 133 has taken a fork
201 68 is sleeping
201 122 is sleeping
201 69 has taken a fork
201 149 has taken a fork
201 101 has taken a fork
201 101 is eating
201 132 is sleeping
201 123 has taken a fork
201 100 is sleeping
201 103 has taken a fork
201 152 is sleeping
201 153 has taken a fork
201 126 is sleeping
201 130 is sleeping
201 79 has taken a fork
201 128 is sleeping
201 77 has taken a fork
201 97 has taken a fork
201 90 is sleeping
201 97 has taken a fork
201 89 has taken a fork
201 150 is sleeping
201 145 has taken a fork
201 79 has taken a fork
201 94 is sleeping
201 123 has taken a fork
201 129 has taken a fork
201 133 has taken a fork
201 146 is sleeping
201 75 has taken a fork
201 75 has taken a fork
201 75 is eating
201 124 is sleeping
201 96 is sleeping
201 86 is sleeping
201 138 is sleeping
201 142 is sleeping
201 98 is sleeping
201 110 is sleeping
201 106 is sleeping
201 85 has taken a fork
201 85 is eating
201 137 has taken a fork
201 137 is eating
201 99 has taken a fork
201 99 has taken a fork
201 99 is eating
201 105 has taken a fork
201 105 is eating
201 76 is sleeping
201 92 is sleeping
201 87 has taken a fork
201 87 has taken a fork
201 87 is eating
201 107 has taken a fork
201 107 has taken a fork
201 107 is eating
201 70 is sleeping
201 127 has taken a fork
201 127 has taken a fork
201 127 is eating
201 64 is sleeping
201 120 is sleeping
201 71 has taken a fork
201 71 has taken a fork
201 140 is sleeping
201 143 has taken a fork
201 143 has taken a fork
201 72 is sleeping
201 119 has taken a fork
201 119 is eating
201 77 has taken a fork
201 77 is eating
201 63 has taken a fork
201 63 has taken a fork
201 63 is eating
201 121 has taken a fork
201 111 has taken a fork
201 65 has taken a fork
201 65 has taken a fork
201 60 is sleeping
201 59 has taken a fork
201 59 is eating
201 73 has taken a fork
201 73 has taken a fork
201 73 is eating
201 141 has taken a fork
201 141 has taken a fork
201 141 is eating
201 61 has taken a fork
201 61 has taken a fork
201 61 is eating
201 78 is sleeping
201 112 is sleeping
201 115 has taken a fork
201 115 has taken a fork
201 115 is eating
201 97 is eating
201 89 is eating
201 149 has taken a fork
201 149 is eating
201 109 has taken a fork
201 109 is eating
201 91 has taken a fork
201 91 has taken a fork
201 91 is eating
201 151 has taken a fork
201 151 has taken a fork
201 113 has taken a fork
201 113 has taken a fork
201 113 is eating
201 74 is sleeping
201 145 has taken a fork
201 145 is eating
201 81 has taken a fork
201 81 has taken a fork
201 123 is eating
201 134 is sleeping
201 129 has taken a fork
201 129 is eating
201 135 has taken a fork
201 135 has taken a fork
201 133 is eating
201 147 has taken a fork
201 147 has taken a fork
201 147 is eating
201 95 has taken a fork
201 95 has taken a fork
201 95 is eating
201 71 is eating
201 143 is eating
201 69 has taken a fork
201 69 is eating
201 93 has taken a fork
201 93 has taken a fork
201 93 is eating
201 111 has taken a fork
201 111 is eating
201 65 is eating
201 66 is sleeping
201 131 has taken a fork
201 131 has taken a fork
201 131 is eating
201 151 is eating
201 80 is sleeping
201 81 is eating
201 144 is sleeping
201 135 is eating
201 125 has taken a fork
201 125 has taken a fork
201 125 is eating
201 67 has taken a fork
201 67 has taken a fork
201 67 is eating
201 121 has taken a fork
201 121 is eating
201 139 has taken a fork
201 79 is eating
201 62 is sleeping
201 114 is sleeping
201 139 has taken a fork
201 139 is eating
202 166 is sleeping
202 167 has taken a fork
202 172 is sleeping
202 181 has taken a fork
202 182 is sleeping
202 156 is sleeping
202 193 has taken a fork
202 193 has taken a fork
202 194 is sleeping
202 192 is sleeping
202 177 has taken a fork
202 163 has taken a fork
202 198 is sleeping
202 199 has taken a fork
202 179 has taken a fork
202 183 has taken a fork
202 187 has taken a fork
202 157 has taken a fork
202 157 has taken a fork
202 157 is eating
202 162 is sleeping
202 188 is sleeping
202 187 has taken a fork
202 187 is eating
202 164 is sleeping
202 171 has taken a fork
202 171 has taken a fork
202 173 has taken a fork
202 195 has taken a fork
202 186 is sleeping
202 177 has taken a fork
202 177 is eating
202 178 is sleeping
202 176 is sleeping
202 179 has taken a fork
202 179 is eating
202 154 is sleeping
202 153 has taken a fork
202 153 is eating
202 180 is sleeping
202 155 has taken a fork
202 155 has taken a fork
202 155 is eating
202 193 is eating
202 181 has taken a fork
202 181 is eating
202 163 has taken a fork
202 163 is eating
202 170 is sleeping
202 165 has taken a fork
202 165 has taken a fork
202 165 is eating
202 161 has taken a fork
202 161 has taken a fork
202 161 is eating
202 158 is sleeping
202 171 is eating
202 183 has taken a fork
202 183 is eating
202 159 has taken a fork
202 159 has taken a fork
202 159 is eating
202 189 has taken a fork
202 184 is sleeping
202 185 has taken a fork
202 185 has taken a fork
202 160 is sleeping
202 185 is eating
202 168 is sleeping
202 169 has taken a fork
202 169 has taken a fork
202 169 is eating
202 167 has taken a fork
202 167 is eating
202 190 is sleeping
202 191 has taken a fork
202 191 has taken a fork
202 191 is eating
202 189 has taken a fork
202 189 is eating
202 196 is sleeping
202 195 has taken a fork
202 174 is sleeping
202 195 is eating
202 173 has taken a fork
202 173 is eating
202 197 has taken a fork
202 197 has taken a fork
202 197 is eating
202 175 has taken a fork
202 175 has taken a fork
202 175 is eating
400 2 is thinking
400 52 is thinking
400 47 is sleeping
400 33 is sleeping
400 38 is thinking
400 49 is sleeping
400 24 is thinking
400 24 has taken a fork
400 27 is sleeping
400 29 is sleeping
400 23 is sleeping
400 19 is sleeping
400 35 is sleeping
400 55 is sleeping
400 11 is sleeping
400 20 is thinking
400 20 has taken a fork
400 25 is sleeping
400 24 has taken a fork
400 24 is eating
400 43 is sleeping
400 7 is sleeping
400 38 has taken a fork
400 38 has taken a fork
400 38 is eating
400 22 is thinking
400 6 is thinking
400 53 is sleeping
400 5 is sleeping
400 21 is sleeping
400 40 is thinking
400 56 is thinking
400 56 has taken a fork
400 12 is thinking
400 56 has taken a fork
400 14 is thinking
400 18 is thinking
400 54 is thinking
400 50 is thinking
400 50 has taken a fork
400 50 has taken a fork
400 50 is eating
400 2 has taken a fork
400 2 has taken a fork
400 2 is eating
400 44 is thinking
400 44 has taken a fork
400 44 has taken a fork
400 44 is eating
400 51 is sleeping
400 31 is sleeping
400 10 is thinking
400 10 has taken a fork
400 10 has taken a fork
400 10 is eating
400 22 has taken a fork
400 22 has taken a fork
400 22 is eating
400 57 is sleeping
400 40 has taken a fork
400 40 has taken a fork
400 40 is eating
400 52 has taken a fork
400 52 has taken a fork
400 52 is eating
400 34 is thinking
400 34 has taken a fork
400 34 has taken a fork
400 34 is eating
400 37 is sleeping
400 20 has taken a fork
400 20 is eating
400 13 is sleeping
400 8 is thinking
400 8 has taken a fork
400 8 has taken a fork
400 8 is eating
400 30 is thinking
400 30 has taken a fork
400 30 has taken a fork
400 30 is eating
400 14 has taken a fork
400 14 has taken a fork
400 14 is eating
400 56 is eating
400 32 is thinking
400 32 has taken a fork
400 39 is sleeping
400 4 is thinking
400 4 has taken a fork
400 4 has taken a fork
400 4 is eating
400 41 is sleeping
400 42 is thinking
400 42 has taken a fork
400 42 has taken a fork
400 42 is eating
400 46 is thinking
400 46 has taken a fork
400 46 has taken a fork
400 46 is eating
400 58 is thinking
400 58 has taken a fork
400 16 is thinking
400 16 has taken a fork
400 16 has taken a fork
400 1 is sleeping
400 200 has taken a fork
400 200 is eating
400 9 is sleeping
400 15 is sleeping
400 48 is thinking
400 48 has taken a fork
400 48 has taken a fork
400 48 is eating
400 6 has taken a fork
400 6 has taken a fork
400 6 is eating
400 12 has taken a fork
400 12 has taken a fork
400 32 has taken a fork
400 18 has taken a fork
400 26 is thinking
400 28 is thinking
400 28 has taken a fork
400 28 has taken a fork
400 28 is eating
400 36 is thinking
400 36 has taken a fork
400 36 has taken a fork
400 36 is eating
400 3 is sleeping
400 17 is sleeping
400 12 is eating
400 32 is eating
400 18 has taken a fork
400 18 is eating
400 26 has taken a fork
400 26 has taken a fork
400 26 is eating
400 54 has taken a fork
400 54 has taken a fork
400 45 is sleeping
400 16 is eating
400 54 is eating
401 105 is sleeping
401 104 has taken a fork
401 104 is eating
401 100 is thinking
401 65 is sleeping
401 111 is sleeping
401 72 is thinking
401 113 is sleeping
401 151 is sleeping
401 64 is thinking
401 71 is sleeping
401 102 is thinking
401 125 is sleeping
401 83 is sleeping
401 150 is thinking
401 72 has taken a fork
401 148 is thinking
401 137 is sleeping
401 95 is sleeping
401 135 is sleeping
401 149 is sleeping
401 102 has taken a fork
401 81 is sleeping
401 93 is sleeping
401 123 is sleeping
401 66 is thinking
401 66 has taken a fork
401 141 is sleeping
401 101 is sleeping
401 142 is thinking
401 142 has taken a fork
401 129 is sleeping
401 91 is sleeping
401 69 is sleeping
401 150 has taken a fork
401 150 has taken a fork
401 150 is eating
401 96 is thinking
401 96 has taken a fork
401 74 is thinking
401 136 is thinking
401 136 has taken a fork
401 136 has taken a fork
401 89 is sleeping
401 145 is sleeping
401 112 is thinking
401 63 is sleeping
401 62 is thinking
401 99 is sleeping
401 59 is sleeping
401 88 is thinking
401 128 is thinking
401 110 is thinking
401 140 is thinking
401 148 has taken a fork
401 86 is thinking
401 86 has taken a fork
401 115 is sleeping
401 78 is thinking
401 78 has taken a fork
401 78 has taken a fork
401 78 is eating
401 77 is sleeping
401 61 is sleeping
401 119 is sleeping
401 131 is sleeping
401 139 is sleeping
401 87 is sleeping
401 97 is sleeping
401 74 has taken a fork
401 74 has taken a fork
401 74 is eating
401 109 is sleeping
401 96 has taken a fork
401 96 is eating
401 133 is sleeping
401 134 is thinking
401 134 has taken a fork
401 134 has taken a fork
401 134 is eating
401 85 is sleeping
401 75 is sleeping
401 130 is thinking
401 130 has taken a fork
401 130 has taken a fork
401 130 is eating
401 112 has taken a fork
401 112 has taken a fork
401 112 is eating
401 82 is thinking
401 82 has taken a fork
401 82 has taken a fork
401 82 is eating
401 118 is thinking
401 66 has taken a fork
401 66 is eating
401 136 is eating
401 127 is sleeping
401 108 is thinking
401 108 has taken a fork
401 108 has taken a fork
401 108 is eating
401 100 has taken a fork
401 100 has taken a fork
401 100 is eating
401 72 has taken a fork
401 72 is eating
401 60 is thinking
401 60 has taken a fork
401 60 has taken a fork
401 122 is thinking
401 122 has taken a fork
401 120 is thinking
401 120 has taken a fork
401 58 has taken a fork
401 58 is eating
401 142 has taken a fork
401 142 is eating
401 116 is thinking
401 147 is sleeping
401 128 has taken a fork
401 128 has taken a fork
401 128 is eating
401 84 is thinking
401 84 has taken a fork
401 84 has taken a fork
401 84 is eating
401 114 is thinking
401 114 has taken a fork
401 114 has taken a fork
401 114 is eating
401 140 has taken a fork
401 140 has taken a fork
401 140 is eating
401 143 is sleeping
401 148 has taken a fork
401 148 is eating
401 138 is thinking
401 138 has taken a fork
401 138 has taken a fork
401 138 is eating
401 107 is sleeping
401 73 is sleeping
401 98 is thinking
401 98 has taken a fork
401 98 has taken a fork
401 79 is sleeping
401 152 is thinking
401 121 is sleeping
401 144 is thinking
401 144 has taken a fork
401 144 has taken a fork
401 144 is eating
401 80 is thinking
401 80 has taken a fork
401 80 has taken a fork
401 80 is eating
401 62 has taken a fork
401 62 has taken a fork
401 62 is eating
401 76 is thinking
401 76 has taken a fork
401 76 has taken a fork
401 76 is eating
401 60 is eating
401 132 is thinking
401 132 has taken a fork
401 132 has taken a fork
401 132 is eating
401 122 has taken a fork
401 122 is eating
401 116 has taken a fork
401 116 has taken a fork
401 116 is eating
401 70 is thinking
401 70 has taken a fork
401 126 is thinking
401 126 has taken a fork
401 110 has taken a fork
401 92 is thinking
401 146 is thinking
401 94 is thinking
401 94 has taken a fork
401 94 has taken a fork
401 94 is eating
401 98 is eating
401 152 has taken a fork
401 124 is thinking
401 124 has taken a fork
401 124 has taken a fork
401 124 is eating
401 90 is thinking
401 118 has taken a fork
401 117 is sleeping
401 120 has taken a fork
401 120 is eating
401 106 is thinking
401 106 has taken a fork
401 70 has taken a fork
401 126 has taken a fork
401 126 is eating
401 110 has taken a fork
401 92 has taken a fork
401 146 has taken a fork
401 86 has taken a fork
401 64 has taken a fork
401 67 is sleeping
401 118 has taken a fork
401 118 is eating
401 88 has taken a fork
401 88 has taken a fork
401 88 is eating
401 70 is eating
401 68 is thinking
401 68 has taken a fork
401 68 has taken a fork
401 68 is eating
401 92 has taken a fork
401 92 is eating
401 86 is eating
401 64 has taken a fork
401 64 is eating
401 90 has taken a fork
401 90 has taken a fork
401 90 is eating
401 110 is eating
401 146 has taken a fork
401 146 is eating
401 106 has taken a fork
401 106 is eating
402 197 is sleeping
402 182 is thinking
402 159 is sleeping
402 191 is sleeping
402 154 is thinking
402 152 has taken a fork
402 152 is eating
402 198 is thinking
402 188 is thinking
402 155 is sleeping
402 166 is thinking
402 167 is sleeping
402 186 is thinking
402 184 is thinking
402 184 has taken a fork
402 185 is sleeping
402 156 is thinking
402 160 is thinking
402 189 is sleeping
402 153 is sleeping
402 172 is thinking
402 172 has taken a fork
402 154 has taken a fork
402 183 is sleeping
402 194 is thinking
402 178 is thinking
402 175 is sleeping
402 187 is sleeping
402 164 is thinking
402 164 has taken a fork
402 164 has taken a fork
402 164 is eating
402 198 has taken a fork
402 174 is thinking
402 188 has taken a fork
402 188 has taken a fork
402 163 is sleeping
402 171 is sleeping
402 170 is thinking
402 166 has taken a fork
402 166 has taken a fork
402 166 is eating
402 161 is sleeping
402 186 has taken a fork
402 186 has taken a fork
402 186 is eating
402 192 is thinking
402 192 has taken a fork
402 184 has taken a fork
402 184 is eating
402 168 is thinking
402 168 has taken a fork
402 156 has taken a fork
402 196 is thinking
402 196 has taken a fork
402 196 has taken a fork
402 196 is eating
402 160 has taken a fork
402 160 has taken a fork
402 180 is thinking
402 180 has taken a fork
402 188 is eating
402 195 is sleeping
402 158 is thinking
402 179 is sleeping
402 176 is thinking
402 176 has taken a fork
402 162 is thinking
402 162 has taken a fork
402 160 is eating
402 154 has taken a fork
402 154 is eating
402 190 is thinking
402 190 has taken a fork
402 162 has taken a fork
402 162 is eating
402 165 is sleeping
402 193 is sleeping
402 173 is sleeping
402 174 has taken a fork
402 174 has taken a fork
402 194 has taken a fork
402 194 has taken a fork
402 194 is eating
402 190 has taken a fork
402 190 is eating
402 172 has taken a fork
402 172 is eating
402 192 has taken a fork
402 174 is eating
402 192 is eating
402 169 is sleeping
402 170 has taken a fork
402 170 has taken a fork
402 170 is eating
402 168 has taken a fork
402 168 is eating
402 177 is sleeping
402 157 is sleeping
402 176 has taken a fork
402 176 is eating
402 178 has taken a fork
402 178 has taken a fork
402 181 is sleeping
402 158 has taken a fork
402 158 has taken a fork
402 158 is eating
402 182 has taken a fork
402 182 has taken a fork
402 182 is eating
402 180 has taken a fork
402 180 is eating
402 178 is eating
402 156 has taken a fork
402 156 is eating
600 42 is sleeping
600 41 is thinking
600 45 is thinking
600 25 is thinking
600 14 is sleeping
600 44 is sleeping
600 45 has taken a fork
600 23 is thinking
600 56 is sleeping
600 25 has taken a fork
600 38 is sleeping
600 45 has taken a fork
600 45 is eating
600 53 is thinking
600 53 has taken a fork
600 53 has taken a fork
600 53 is eating
600 33 is thinking
600 29 is thinking
600 13 is thinking
600 13 has taken a fork
600 13 has taken a fork
600 13 is eating
600 34 is sleeping
600 30 is sleeping
600 16 is sleeping
600 55 is thinking
600 55 has taken a fork
600 55 has taken a fork
600 55 is eating
600 35 is thinking
600 35 has taken a fork
600 35 has taken a fork
600 35 is eating
600 10 is sleeping
600 32 is sleeping
600 26 is sleeping
600 1 is thinking
600 1 has taken a fork
600 1 has taken a fork
600 1 is eating
600 11 is thinking
600 11 has taken a fork
600 11 has taken a fork
600 11 is eating
600 12 is sleeping
600 20 is sleeping
600 17 is thinking
600 17 has taken a fork
600 17 has taken a fork
600 17 is eating
600 57 is thinking
600 57 has taken a fork
600 2 is sleeping
600 21 is thinking
600 21 has taken a fork
600 41 has taken a fork
600 9 is thinking
600 9 has taken a fork
600 31 is thinking
600 31 has taken a fork
600 43 is thinking
600 37 is thinking
600 37 has taken a fork
600 37 has taken a fork
600 37 is eating
600 54 is sleeping
600 49 is thinking
600 49 has taken a fork
600 49 has taken a fork
600 200 is sleeping
600 8 is sleeping
600 23 has taken a fork
600 23 has taken a fork
600 23 is eating
600 52 is sleeping
600 4 is sleeping
600 39 is thinking
600 39 has taken a fork
600 39 has taken a fork
600 39 is eating
600 48 is sleeping
600 199 has taken a fork
600 199 is eating
600 33 has taken a fork
600 33 has taken a fork
600 33 is eating
600 29 has taken a fork
600 29 has taken a fork
600 29 is eating
600 3 is thinking
600 3 has taken a fork
600 3 has taken a fork
600 3 is eating
600 47 is thinking
600 47 has taken a fork
600 47 has taken a fork
600 51 is thinking
600 51 has taken a fork
600 15 is thinking
600 15 has taken a fork
600 15 has taken a fork
600 15 is eating
600 41 has taken a fork
600 41 is eating
600 25 has taken a fork
600 25 is eating
600 9 has taken a fork
600 9 is eating
600 31 has taken a fork
600 31 is eating
600 5 is thinking
600 5 has taken a fork
600 5 has taken a fork
600 5 is eating
600 22 is sleeping
600 7 is thinking
600 7 has taken a fork
600 7 has taken a fork
600 7 is eating
600 36 is sleeping
600 19 is thinking
600 19 has taken a fork
600 19 has taken a fork
600 19 is eating
600 27 is thinking
600 27 has taken a fork
600 27 has taken a fork
600 27 is eating
600 40 is sleeping
600 24 is sleeping
600 46 is sleeping
600 21 has taken a fork
600 21 is eating
600 6 is sleeping
600 43 has taken a fork
600 43 has taken a fork
600 43 is eating
600 49 is eating
600 18 is sleeping
600 28 is sleeping
600 47 is eating
600 51 has taken a fork
600 51 is eating
600 50 is sleeping
601 138 is sleeping
601 82 is sleeping
601 147 is thinking
601 101 is thinking
601 143 is thinking
601 92 is sleeping
601 131 is thinking
601 104 is sleeping
601 80 is sleeping
601 84 is sleeping
601 98 is sleeping
601 86 is sleeping
601 67 is thinking
601 114 is sleeping
601 133 is thinking
601 133 has taken a fork
601 111 is thinking
601 135 is thinking
601 73 is thinking
601 124 is sleeping
601 122 is sleeping
601 79 is thinking
601 119 is thinking
601 130 is sleeping
601 87 is thinking
601 78 is sleeping
601 87 has taken a fork
601 87 has taken a fork
601 87 is eating
601 76 is sleeping
601 65 is thinking
601 88 is sleeping
601 107 is thinking
601 133 has taken a fork
601 123 is thinking
601 150 is sleeping
601 145 is thinking
601 105 is thinking
601 105 has taken a fork
601 96 is sleeping
601 57 has taken a fork
601 100 is sleeping
601 121 is thinking
601 121 has taken a fork
601 149 is thinking
601 121 has taken a fork
601 91 is thinking
601 110 is sleeping
601 74 is sleeping
601 118 is sleeping
601 66 is sleeping
601 97 is thinking
601 68 is sleeping
601 116 is sleeping
601 67 has taken a fork
601 67 has taken a fork
601 67 is eating
601 129 is thinking
601 129 has taken a fork
601 129 has taken a fork
601 129 is eating
601 148 is sleeping
601 117 is thinking
601 117 has taken a fork
601 117 has taken a fork
601 117 is eating
601 95 is thinking
601 95 has taken a fork
601 90 is sleeping
601 134 is sleeping
601 108 is sleeping
601 64 is sleeping
601 83 is thinking
601 83 has taken a fork
601 83 has taken a fork
601 135 has taken a fork
601 135 has taken a fork
601 135 is eating
601 107 has taken a fork
601 107 has taken a fork
601 107 is eating
601 133 is eating
601 112 is sleeping
601 132 is sleeping
601 125 is thinking
601 125 has taken a fork
601 125 has taken a fork
601 125 is eating
601 147 has taken a fork
601 147 has taken a fork
601 147 is eating
601 93 is thinking
601 93 has taken a fork
601 93 has taken a fork
601 93 is eating
601 128 is sleeping
601 62 is sleeping
601 59 is thinking
601 59 has taken a fork
601 59 has taken a fork
601 59 is eating
601 99 is thinking
601 99 has taken a fork
601 109 is thinking
601 109 has taken a fork
601 142 is sleeping
601 143 has taken a fork
601 143 has taken a fork
601 143 is eating
601 94 is sleeping
601 72 is sleeping
601 57 is eating
601 120 is sleeping
601 101 has taken a fork
601 73 has taken a fork
601 73 has taken a fork
601 73 is eating
601 131 has taken a fork
601 131 has taken a fork
601 131 is eating
601 69 is thinking
601 69 has taken a fork
601 69 has taken a fork
601 69 is eating
601 70 is sleeping
601 121 is eating
601 149 has taken a fork
601 149 has taken a fork
601 149 is eating
601 91 has taken a fork
601 91 has taken a fork
601 91 is eating
601 111 has taken a fork
601 111 has taken a fork
601 111 is eating
601 79 has taken a fork
601 79 has taken a fork
601 79 is eating
601 127 is thinking
601 127 has taken a fork
601 127 has taken a fork
601 127 is eating
601 119 has taken a fork
601 119 has taken a fork
601 119 is eating
601 103 has taken a fork
601 103 is eating
601 140 is sleeping
601 71 is thinking
601 71 has taken a fork
601 71 has taken a fork
601 61 is thinking
601 61 has taken a fork
601 61 has taken a fork
601 113 is thinking
601 113 has taken a fork
601 113 has taken a fork
601 113 is eating
601 65 has taken a fork
601 65 has taken a fork
601 65 is eating
601 146 is sleeping
601 115 is thinking
601 115 has taken a fork
601 115 has taken a fork
601 141 is thinking
601 141 has taken a fork
601 123 has taken a fork
601 123 has taken a fork
601 60 is sleeping
601 99 has taken a fork
601 99 is eating
601 58 is sleeping
601 105 has taken a fork
601 105 is eating
601 75 is thinking
601 75 has taken a fork
601 75 has taken a fork
601 75 is eating
601 126 is sleeping
601 144 is sleeping
601 151 is thinking
601 151 has taken a fork
601 136 is sleeping
601 85 is thinking
601 85 has taken a fork
601 85 has taken a fork
601 85 is eating
601 97 has taken a fork
601 97 has taken a fork
601 97 is eating
601 71 is eating
601 61 is eating
601 106 is sleeping
601 137 is thinking
601 137 has taken a fork
601 137 has taken a fork
601 137 is eating
601 83 is eating
601 115 is eating
601 141 has taken a fork
601 141 is eating
601 139 is thinking
601 139 has taken a fork
601 139 has taken a fork
601 139 is eating
601 81 is thinking
601 81 has taken a fork
601 81 has taken a fork
601 81 is eating
601 89 is thinking
601 89 has taken a fork
601 89 has taken a fork
601 89 is eating
601 77 is thinking
601 77 has taken a fork
601 77 has taken a fork
601 77 is eating
601 95 has taken a fork
601 95 is eating
601 123 is eating
601 109 has taken a fork
601 109 is eating
601 145 has taken a fork
601 145 has taken a fork
601 145 is eating
601 63 is thinking
601 63 has taken a fork
601 63 has taken a fork
601 63 is eating
602 156 is sleeping
602 187 is thinking
602 181 is thinking
602 192 is sleeping
602 188 is sleeping
602 164 is sleeping
602 177 is thinking
602 174 is sleeping
602 180 is sleeping
602 181 has taken a fork
602 181 has taken a fork
602 181 is eating
602 178 is sleeping
602 175 is thinking
602 171 is thinking
602 175 has taken a fork
602 175 has taken a fork
602 175 is eating
602 197 is thinking
602 163 is thinking
602 194 is sleeping
602 167 is thinking
602 196 is sleeping
602 172 is sleeping
602 162 is sleeping
602 190 is sleeping
602 169 is thinking
602 169 has taken a fork
602 169 has taken a fork
602 169 is eating
602 179 is thinking
602 179 has taken a fork
602 179 has taken a fork
602 179 is eating
602 168 is sleeping
602 159 is thinking
602 159 has taken a fork
602 159 has taken a fork
602 159 is eating
602 182 is sleeping
602 160 is sleeping
602 183 is thinking
602 183 has taken a fork
602 183 has taken a fork
602 183 is eating
602 186 is sleeping
602 187 has taken a fork
602 187 has taken a fork
602 187 is eating
602 155 is thinking
602 155 has taken a fork
602 155 has taken a fork
602 161 is thinking
602 161 has taken a fork
602 161 has taken a fork
602 161 is eating
602 185 is thinking
602 176 is sleeping
602 177 has taken a fork
602 170 is sleeping
602 191 is thinking
602 191 has taken a fork
602 157 is thinking
602 157 has taken a fork
602 157 has taken a fork
602 163 has taken a fork
602 193 is thinking
602 184 is sleeping
602 189 is thinking
602 158 is sleeping
602 195 is thinking
602 155 is eating
602 154 is sleeping
602 185 has taken a fork
602 185 has taken a fork
602 185 is eating
602 177 has taken a fork
602 177 is eating
602 171 has taken a fork
602 171 has taken a fork
602 171 is eating
602 197 has taken a fork
602 157 is eating
602 163 has taken a fork
602 163 is eating
602 193 has taken a fork
602 193 has taken a fork
602 195 has taken a fork
602 195 has taken a fork
602 191 has taken a fork
602 189 has taken a fork
602 193 is eating
602 195 is eating
602 191 is eating
602 189 has taken a fork
602 189 is eating
602 165 is thinking
602 165 has taken a fork
602 173 is thinking
602 173 has taken a fork
602 173 has taken a fork
602 173 is eating
602 153 is thinking
602 152 is sleeping
602 153 has taken a fork
602 153 has taken a fork
602 165 has taken a fork
602 151 has taken a fork
602 151 is eating
602 153 is eating
602 165 is eating
602 166 is sleeping
602 167 has taken a fork
602 167 has taken a fork
602 167 is eating
800 23 is sleeping
800 13 is sleeping
800 20 is thinking
800 56 is thinking
800 28 is thinking
800 28 has taken a fork
800 48 is thinking
800 14 is thinking
800 6 is thinking
800 10 is thinking
800 12 is thinking
800 12 has taken a fork
800 12 has taken a fork
800 12 is eating
800 43 is sleeping
800 22 is thinking
800 22 has taken a fork
800 22 has taken a fork
800 22 is eating
800 16 is thinking
800 16 has taken a fork
800 16 has taken a fork
800 16 is eating
800 5 is sleeping
800 2 is thinking
800 2 has taken a fork
800 2 has taken a fork
800 2 is eating
800 27 is sleeping
800 199 is sleeping
800 31 is sleeping
800 198 has taken a fork
800 198 is eating
800 9 is sleeping
800 49 is sleeping
800 19 is sleeping
800 47 is sleeping
800 1 is sleeping
800 26 is thinking
800 26 has taken a fork
800 26 has taken a fork
800 26 is eating
800 50 is thinking
800 50 has taken a fork
800 50 has taken a fork
800 50 is eating
800 33 is sleeping
800 29 is sleeping
800 36 is thinking
800 36 has taken a fork
800 41 is sleeping
800 48 has taken a fork
800 48 has taken a fork
800 48 is eating
800 21 is sleeping
800 53 is sleeping
800 32 is thinking
800 32 has taken a fork
800 28 has taken a fork
800 28 is eating
800 51 is sleeping
800 44 is thinking
800 44 has taken a fork
800 44 has taken a fork
800 44 is eating
800 4 is thinking
800 200 is thinking
800 200 has taken a fork
800 200 has taken a fork
800 46 is thinking
800 46 has taken a fork
800 15 is sleeping
800 3 is sleeping
800 7 is sleeping
800 8 is thinking
800 8 has taken a fork
800 8 has taken a fork
800 8 is eating
800 20 has taken a fork
800 20 has taken a fork
800 20 is eating
800 10 has taken a fork
800 10 has taken a fork
800 10 is eating
800 40 is thinking
800 40 has taken a fork
800 40 has taken a fork
800 40 is eating
800 37 is sleeping
800 24 is thinking
800 24 has taken a fork
800 24 has taken a fork
800 39 is sleeping
800 38 is thinking
800 30 is thinking
800 52 is thinking
800 25 is sleeping
800 36 has taken a fork
800 36 is eating
800 11 is sleeping
800 32 has taken a fork
800 32 is eating
800 56 has taken a fork
800 4 has taken a fork
800 4 has taken a fork
800 4 is eating
800 17 is sleeping
800 200 is eating
800 46 has taken a fork
800 46 is eating
800 18 is thinking
800 18 has taken a fork
800 18 has taken a fork
800 18 is eating
800 45 is sleeping
800 34 is thinking
800 34 has taken a fork
800 34 has taken a fork
800 34 is eating
800 30 has taken a fork
800 30 has taken a fork
800 52 has taken a fork
800 52 has taken a fork
800 52 is eating
800 42 is thinking
800 42 has taken a fork
800 42 has taken a fork
800 42 is eating
800 6 has taken a fork
800 6 has taken a fork
800 6 is eating
800 24 is eating
800 38 has taken a fork
800 38 has taken a fork
800 38 is eating
800 35 is sleeping
800 55 is sleeping
800 14 has taken a fork
800 14 has taken a fork
800 14 is eating
800 30 is eating
800 54 is thinking
800 54 has taken a fork
800 54 has taken a fork
800 54 is eating
801 102 died
801 93 is sleeping
"""

# Step 1: Parse the input data
def parse_data(data):
    actions = []
    for line in data.strip().split('\n'):
        parts = line.split(' ')
        timestamp, philo_id, action = int(parts[0]), int(parts[1]), ' '.join(parts[2:])
        actions.append({'timestamp': timestamp, 'philo_id': philo_id, 'action': action})
    return actions

# Parse the data using your function
actions_data = parse_data(data)

# Sort the actions by philosopher id and timestamp
actions_data.sort(key=lambda x: (x['philo_id'], x['timestamp']))

# Process the actions to determine the duration of each action
processed_actions = []
for i, action in enumerate(actions_data):
    if i < len(actions_data) - 1 and actions_data[i + 1]['philo_id'] == action['philo_id']:
        # If the next action is by the same philosopher, the current action ends when the next one starts
        end_time = actions_data[i + 1]['timestamp']
    else:
        # Otherwise, we don't know when the action ends, so we can set a default duration or leave it open
        end_time = action['timestamp'] + 1  # Assuming a default duration of 1 for the last action
    processed_actions.append({
        'philo_id': action['philo_id'],
        'start': action['timestamp'],
        'end': end_time,
        'action': action['action']
    })

# Define colors for different actions
color_dict = {
    'has taken a fork': 'skyblue',
    'is eating': 'salmon',
    'is sleeping': 'lightgreen',
    'is thinking': 'lightgrey'
}

# Create the Gantt chart
fig, ax = plt.subplots(figsize=(15, 8))

for action in processed_actions:
    start = action['start']
    duration = action['end'] - action['start']
    philo_id = action['philo_id']
    color = color_dict.get(action['action'], 'black')
    ax.broken_barh([(start, duration)], (philo_id - 0.4, 0.8), facecolors=color)

# Set the y-axis to show philosopher IDs
ax.set_yticks(range(1, len(color_dict) + 1))
ax.set_yticklabels(range(1, len(color_dict) + 1))
ax.set_xlabel('Time')
ax.set_ylabel('Philosopher ID')
ax.set_title('Philosopher Actions Over Time')

# Create a custom legend
from matplotlib.patches import Patch
legend_elements = [Patch(facecolor=color, label=action) for action, color in color_dict.items()]
ax.legend(handles=legend_elements, loc='upper left')

plt.show()