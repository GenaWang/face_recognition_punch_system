import subprocess

names = ['wwe', 'sss', 'aaa', 'bbb', 'ddd', 'ccc', 'eee', 'rrr', 'fff', 'ggg', 'yyy', 'xxx']

def insertNameToMysql(detectedNames):
	for name in detectedNames:
		pro = subprocess.Popen(['./record_face_data.exe', name])
		pro.wait()

if __name__ == '__main__':
	insertNameToMysql(names)