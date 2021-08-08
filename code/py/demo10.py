import codeforces_api
import json


cf_api = codeforces_api.CodeforcesApi("0d63cc780b50d426bd02b0c70993548253aa7cb0", "35135ad1efc61bedd1401c19bd41f5dc51840a21")
anonim_cf_api = codeforces_api.CodeforcesApi()

parser = codeforces_api.CodeforcesParser()
STANDINGS = cf_api.contest_status(1355, start=10, count=20)
# ans = anonim_cf_api.contest_list()
# view = anonim_cf_api.contest_rating_changes(1355)
# print(view)
# result = view['result']
# string = json.dumps(view)

print(STANDINGS)

