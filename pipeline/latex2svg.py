import os
import requests
from requests.structures import CaseInsensitiveDict

post_url = "https://e1kf0882p7.execute-api.us-east-1.amazonaws.com/default/latex2image"
post_headers = CaseInsensitiveDict()
post_headers["Content-Type"] = "application/json"

for filename in os.scandir("../images/latex/snippets"):
    if filename.is_file():
        print(filename.name[:-4])
        with open(filename.path) as f:
            data = """
            {
            "latexInput":"LaTeX",
            "outputFormat":"SVG",
            "outputScale":"100%"
            }
            """
            latex = f.read().replace("\\","\\\\")
            post_data = data.replace("LaTeX", latex[:-1])
            get_link = requests.post(post_url, headers=post_headers, data=post_data).json()["imageUrl"]

            svg_file = open("../images/latex/renders/"+filename.name[:-3]+"svg", 'w')
            print(requests.get(url = get_link).text, file = svg_file)
            svg_file.close()
